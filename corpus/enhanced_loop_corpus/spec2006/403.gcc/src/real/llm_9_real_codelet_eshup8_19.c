#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short newbyt;
extern unsigned short oldbyt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < (6 + 5); i += 2) {
        unsigned short temp1 = *x >> 8;
        unsigned short temp2 = *x << 8;
        *x = temp2 | (oldbyt & 0xFF);
        oldbyt = temp1;
        x -= (i % 4 == 1) ? 1 : 0;
    }
}
