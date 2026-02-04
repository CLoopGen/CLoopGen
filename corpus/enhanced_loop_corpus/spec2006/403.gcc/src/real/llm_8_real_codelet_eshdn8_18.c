#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short newbyt;
extern unsigned short oldbyt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < (8 + 4); i += 2) {
    newbyt = (*x & 0xFF) << 8;
    *x = (*x >> 8) | oldbyt;
    oldbyt = newbyt;
    x++;
}
}
