# Casino
### By Ethan Kemp (ekogii)
---

This is my casino, and it is just a basic CLI for use by my friends with gambling addictions.

## Installation
1. Download the latest release of the source code (found in the *Releases* tab)
2. Extract the .tar.gz (or the .zip)
3. CD into the place you downloaded the code, and run `make`. (assuming you have GNU Make installed)
4. This next step will vary depending on whether you want to install my casino *Locally* or *Globally* (system-wide).
	#### 4a. Locally
	Run:
	```
	make -s install-local
	```
	#### 4b. Globally
	Run:
	```
	sudo make install
	```
	> Note:
*You can replace `sudo` with any other privellege-escalating tool, such `pkexec` or `su`. (you must use **-c** for `su`)*


## How to use
Upon running for the first time after installation, you will get a message that looks something like the following:
```
Welcome to my casino!

Because this is your first time playing this, you are
gonna start off with a significant... $1000! (not 1000 factorial)

Run 'casino --help' to figure out what to do with that money!!
```

Running `casino -h` or `casino --help` will print the usage information.
```
Usage: casino [options] {mode}
Options:
  -h,--help     Print this message
  -v,--version  Print the version of the casino.

Modes:
  reset         Fully reset your money count.

  roulette      Play roulette.
  slots         Play slot machines.
```

For example, if you wanted to play roulette, you would run `casino roulette`.

---

### **Have fun gambling!**
