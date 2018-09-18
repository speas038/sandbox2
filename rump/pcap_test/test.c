

#include <pcap/pcap.h>


void block_ip( const char *Ip_str )
{
    char err[PCAP_ERRBUF_SIZE];
    const char * iface = NULL;

    pcap_create( iface, (char *)&err );

}

int main()
{

    printf("Attempting to block ip \n" );

    block_ip( "10.30.30.99" );


}
