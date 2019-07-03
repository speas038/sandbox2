#include<stdio.h>
#include<unistd.h>

int main ()
{

    for( int i = 0; i < 15; i++ )
    {
        printf( "this is a test\n");
        fflush( stdout );
    }

    sleep(1);   
    return 0;
}
