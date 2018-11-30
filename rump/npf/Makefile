CC = x86_64-rumprun-netbsd-gcc 
CFLAGS = -std=gnu99 -Wall -Wno-missing-braces
CFLAGS+=-ggdb


BAKE=rumprun-bake
BAKE_FLAGS=-c npftest.config xen_npf

APPNAME=rump_server

SOURCES=rump_server.c

ARCHIVES=

all: $(APPNAME).run

$(APPNAME).run: $(APPNAME).bin
	$(BAKE) $(BAKE_FLAGS) $@ $^ $(ARCHIVES)
	@echo "Run   ./run.sh"
	@echo "Or debug with ./debug.sh and"
	@echo " gdb -ex 'target remote localhost:1234' $@"

$(APPNAME).bin: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^


clean:
	rm -f $(APPNAME).run $(APPNAME).bin *.o
