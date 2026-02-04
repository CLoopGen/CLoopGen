#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        *x++ = 0;
        *x++ = 0;
        *x++ = 0;
        *x++ = 0;
        *x++ = 0;
        *x++ = 0;
    }
}
