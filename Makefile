CC = gcc
CFLAGS = -o bin/casino -Wall

src/main.c: clean
	mkdir bin
	$(CC) $(CFLAGS) src/*.[cos]

install: bin/casino
	cp bin/casino /usr/bin

install-local: bin/casino
	mkdir -p ~/.local/bin
	cp bin/casino ~/.local/bin
	
	bash ./install-local.sh

clean:
	rm -rf bin
