#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


#define MAX_ACCEPTS 1
#define PORT 8080

int main( int argc, const char* argv[] )
{

    int err = 0;
    int accept_fd = 0;
    struct sockaddr_in accept_addr = {0};
    int con_fds[ MAX_ACCEPTS ] = {0};
    struct sockaddr_in con_addrs[ MAX_ACCEPTS ] = {0};
    socklen_t casize = 0;

    accept_fd = socket( AF_INET, SOCK_STREAM, 0 );
    if( !accept_fd )
    {
        perror("Socket Error");
    }
    
    accept_addr.sin_family = AF_INET;
    accept_addr.sin_port = htons( PORT );
    accept_addr.sin_addr.s_addr = INADDR_ANY;

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

    printf( "Accepting connections on port %d\n", PORT );

    for( int i = 0; i < MAX_ACCEPTS; i++ )
    {
        con_fds[i] = accept( accept_fd, (struct sockaddr*)&con_addrs[i], &casize );
        if( ! con_fds[i] )
        {
            perror("Accept Error");
        }
    }

    printf("Close connections? \n");
    getchar();

    for( int i = 0; i < MAX_ACCEPTS; i++ )
    {
        close( con_fds[i] );
    }

    close( accept_fd );

}
