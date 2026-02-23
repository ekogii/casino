CC = cc
CFLAGS = -obin/casino

main.c: clean
	mkdir bin
	$(CC) $(CFLAGS) src/*.[cos]
	
clean:
	rm -rf bin
