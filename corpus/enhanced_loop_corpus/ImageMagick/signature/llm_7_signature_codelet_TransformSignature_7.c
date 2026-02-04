#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *p;
extern unsigned int T;
extern unsigned int W[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[16];
    for (i = 0; i < 16; i++) {
        T = (*((unsigned int *)(p + i * 4)));
        temp[i] = ((T << 24) & 4278190080U) | ((T << 8) & 16711680) | ((T >> 8) & 65280) | ((T >> 24) & 255);
    }
    for (i = 0; i < 16; i++) {
        W[i] = temp[i];
    }
}
