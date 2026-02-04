#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short newbyt;
extern unsigned short oldbyt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short temp;
    for (i = 2; i < (6 + 3); i++) {
        temp = *x >> 8;
        newbyt = *x << 8;
        *x = (*x & 0xFF) | oldbyt;
        oldbyt = temp;
        ++x;
    }
}
