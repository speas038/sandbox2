all: test-rumprun test


test-rumprun: test
	rumprun-bake -c xenevents.conf xen_events test-rumprun test


test: test.c
	x86_64-rumprun-netbsd-gcc test.c -o test


clean:
	rm -f test-rumprun test
