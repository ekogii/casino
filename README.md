# Casino
### By Ethan Kemp (ekogii)
---

This is my casino, and it is just an extremely basic (for now) CLI that I made for all my friends with a gambling addiction, myself *[excluded](./exclude.md)*.

## Installation
1. Download the latest release of the source code (found in the *Releases* tab)
2. Extract the .tar.gz
3. CD into the place you downloaded the code, and run the following command:
```
make && sudo make install
```
> Note:
*If you wish to only install my casino locally (inside your home directory), instead you should run `make && make -s install-local`*

And you are done with the installation!

## How to use
If you are running this for the first time after installation, you should get a message that looks something along the lines of the following:
```
Welcome to my casino!

Because this is your first time playing this, you are
gonna start off with a significant... $1000! (not 1000 factorial)

Run '/path/to/casino --help' to figure out what to do with that money!!
```

Running `/path/to/casino --help` or `/path/to/casino -h` should print the usage information.
```
Usage: /path/to/casino [options] mode...
Options:
  -h,--help     Print this message
  -v,--version  Print the version of the casino.

Modes:
  reset         Fully reset your money count.

  roulette      Play roulette.
  slots         Play slot machines.
```

> *I know I put  an ellipsis after the mode, but you really can only do one mode at once, unfortunately enough.*

For example, if you wanted to play roulette, you would run `/path/to/casino roulette`.

Currently the usage should say `slots`, however the slot machines are currently a work in progress. Observe:
```
You have $1000
Mode you chose: slots

The slot machines are still a work in progress!
Be sure to come back later when I finish them...

[1]    55822 IOT instruction (core dumped)  /path/to/casino slots
```

**For now though, that is all of the modes for the casino**


## Conclusion
As a wise man once said,\
***"Limited time flavour, Lays wavy Funyuns, onion flavoured Funyuns, onion flavoured rings."***

### **Take care and have fun gambling!**
