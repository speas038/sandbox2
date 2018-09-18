#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <npf.h>

#define MAX_ACCEPTS 3
#define PORT 8080


//https://github.com/rumpkernel/wiki/wiki/Howto:-configure-the-npf-packet-filter


int
block_ip( const char* ip_str )
{
//    struct sock_filter myfilter = {0};

    struct nl_config_t * test_config = NULL;

    //test_config = npf_config_create();

    

    printf("IP address to block: %s\n", ip_str );

}

int main( int argc, const char* argv[] )
{

    int err = 0;
    int accept_fd = 0;
    int con_fd = {0};
    struct sockaddr_in accept_addr = {0};
    struct sockaddr_in con_addr = {0};
    socklen_t casize = 0;
    
    casize = sizeof( con_addr );

    accept_addr.sin_family = AF_INET;
    accept_addr.sin_port = htons( PORT );

    accept_fd = socket( AF_INET, SOCK_STREAM, 0 );
    if( !accept_fd )
    {
        perror("Socket Error");
    }

    err = bind( accept_fd, ( struct sockaddr* )&accept_addr, sizeof( accept_addr ) );
    if( err )
    {
        perror("Bind Error");
    }

    err = listen( accept_fd, 100 );
    if( err )
    {
        perror("Listen Error");
    }


    block_ip( "10.30.30.107" ); 


    for( int i = 0; i < MAX_ACCEPTS; i++ )
    {
        con_fd = accept( accept_fd, (struct sockaddr*)&con_addr, &casize );
        if( !con_fd )
        {
            perror("Accept Error");
        }

	printf( "Accepted connection from 0x%x - %s\n", 
		con_addr.sin_addr.s_addr, 
		inet_ntoa( con_addr.sin_addr ));

	close( con_fd );
    }

    close( accept_fd );

}
