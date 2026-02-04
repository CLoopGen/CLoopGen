#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short temp;
    for (i = 2; i < (6 + 3) - 1; i++) {
        temp = *x++;
        *p++ = temp;
    }
}
