#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short newbyt;
extern unsigned short oldbyt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < (6 + 3); i++) {
    newbyt = *x >> 8;
    *x <<= 8;
    if (oldbyt != 0) {
        *x |= oldbyt;
    }
    oldbyt = newbyt;
    --x;
}
}
