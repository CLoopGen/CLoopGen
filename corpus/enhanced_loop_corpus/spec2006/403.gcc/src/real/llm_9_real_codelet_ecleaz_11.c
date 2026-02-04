#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (6 + 3); i++) {
        *xi++ = (unsigned short)(i * i + 2 * i + 1);
    }
}
