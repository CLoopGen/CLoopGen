#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < (6 + 3) - 1; i++) {
        unsigned short temp = *x++;
        *p++ = temp ^ 0xFFFF;
        *p++ = temp;
        *p++ = temp >> 1;
    }
}
