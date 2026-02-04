#include <stdio.h>

#include <inttypes.h>

extern void *buf;
extern unsigned char *cp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (cp = buf, j = 0; j < i * 2; j++) {
        cp[j % (i ? i : 1)] ^= 255;
    }
}
