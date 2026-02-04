#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short newbyt;
extern unsigned short oldbyt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < (8 + 3); i++) {
        newbyt = (*x >> 12) & 0xF;
        *x <<= 4;
        *x |= (oldbyt & 0xF);
        oldbyt = newbyt;
        if (i % 2 == 0) {
            --x;
        }
    }
}
