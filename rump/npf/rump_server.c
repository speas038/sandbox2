#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysctl.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <fcntl.h>
#include <npf.h>

//#include <rump/rump.h>
//#include <rump/rump_syscalls.h>
//#include <rump/rumpdefs.h>
//#include <rump/rumperr.h>

#define CONFIG_TEXT "test test test test"

int main( )
{
//    asm("int3");

    FILE *conf_file = NULL;
    int rc = 0;
    int fd = 0;
    int ver = 0;
    
    conf_file = fopen("/npf.conf", "w+" );
    if( ! conf_file )
    {
        printf( "Could not create npf.cfg\n" );
        goto ErrorExit;
    }

    rc = fprintf( conf_file, "group default {\n\truleset \"test-set\"\n\tpass all\n}" );
    if( ! rc )
    {
        perror("fprintf");
        goto ErrorExit;
    }
    
    fflush( conf_file );
    fclose( conf_file );
    
    printf( "Melania Trump: Hello?\n" );

    fd = open( "/dev/npf", O_RDONLY );

    if ( ioctl( fd, IOC_NPF_VERSION, &ver ) == -1 )
        perror( "IOC_NPF_VERSION" );

    printf( "npf_version: %d", ver );
    fflush( stdout );

//    while(1)
    {
        sleep( 1 );
        sched_yield();
    }
    
ErrorExit:
    return 0;
}
