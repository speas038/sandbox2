#!/bin/bash

IP=10.30.30.134
APPNAME=rump_server


#rumprun -S xen -dip -D 1234 -e RUMPRUN_SYSPROXY=tcp://0.0.0.0:8888 -M 512 -N test-rump\
rumprun -S xen -di -e RUMPRUN_SYSPROXY=tcp://0.0.0.0:8888 -M 512 -N test-rump\
    -I xen0,xenif \
	-W xen0,inet,static,$IP/24 \
	./$APPNAME.run


#sudo /home/alex/rump/rumprun/rumprun/bin/rumprun xen -di \
#	-I xen0,xenif \
#	-W xen0,inet,dhcp \
#	./test.run
