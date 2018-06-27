# QuickHex
A very simple C Hex Dump tool built for learning purposes and out of boredom.

It does what it says on the tin. Creates a hex dump of whatever you feed it with. You can specify the offset from where you want the hex dump to begin. For example, if you specify 0 it will dump the whole file. 

I am not entirely sure how useful this is (probably `NULL`) but it was a nice little project for me to get familiar with HEX and the structure of the binaries. The core of the program is snatched from my other project, MachDump which is a far more sophisticated one. 

I guess it is useful if you wanna do quick dumps in your C tool without having to rely on complicated libraries or on `xxd`.

### Usage
`./quickhex <file> offset`
The offset is a signed integer.

If you don't get it right, the program will tell you that you should probably specify the missing parameter.

### Compiling
```bash
cd /folder of the source
make
```
Alternatively. you can compile it with `gcc quickhex.c -o QuickHex`

### Operating System dependency
It was built on raw C, no macOS specific stuff so it should happily build on any OS capable to compile C.
It uses the following imports so I assume it shouldn't have problems on most OSes.

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
```
### Contact me
Twitter: https://twitter.com/FCE365
