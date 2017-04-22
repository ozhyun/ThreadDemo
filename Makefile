#
#

PROG=test

all: $(PROG)

$(PROG): thread.c
	gcc -g -pthread -o $@ $<

clean:
	@rm -f *.o
