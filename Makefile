CC = cc
CFLAGS = -obin/casino

src/main.c: clean
	mkdir bin
	$(CC) $(CFLAGS) src/*.[cos]
	
clean:
	rm -rf bin
