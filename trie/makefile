CFLAGS=-Wall -pedantic --std=c17
LINKED_DIR=linkedchar/

linkedtest:	
	make clean
	gcc $(CFLAGS) $(LINKED_DIR)charnode.c $(LINKED_DIR)linkedchar.c $(LINKED_DIR)linkedtest.c -o linkedtest

clean:
	rm -f linkedtest
