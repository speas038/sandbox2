#!/bin/bash

IP=10.30.30.134
APPNAME=filesystem_test
DBG_ARGS=
RUMP_SERVER=

set -x

while getopts "ds" opt; do
    case $opt in
        d)
        DBG_ARGS=" -p -D 1234 "
        ;; 
        s)
        RUMPRUN_SYSPROXY=" -e RUMPRUN_SYSPROXY=tcp://0.0.0.0:8888 "
        ;;
    esac
done

rumprun -S xen -di $DBG_ARGS $RUMP_SYSPROXY -M 256 -N $APPNAME-rump\
	-I xen0,xenif \
	-W xen0,inet,static,$IP/24 \
	./$APPNAME.run


#sudo /home/alex/rump/rumprun/rumprun/bin/rumprun xen -di \
#	-I xen0,xenif \
#	-W xen0,inet,dhcp \
#	./test.run
