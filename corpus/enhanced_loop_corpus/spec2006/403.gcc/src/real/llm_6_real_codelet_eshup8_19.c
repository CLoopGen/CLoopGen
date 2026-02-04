#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short newbyt;
extern unsigned short oldbyt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short temp;
    for (i = 2; i < (6 + 3); i++) {
        temp = *x >> 8;
        *x <<= 8;
        *x |= oldbyt;
        oldbyt = temp;
        x--; 
    }
}
