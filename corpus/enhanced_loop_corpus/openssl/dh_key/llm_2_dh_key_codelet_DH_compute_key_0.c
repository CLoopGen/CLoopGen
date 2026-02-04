#include <stdio.h>

#include <inttypes.h>

extern unsigned char *key;
extern int ret;
extern int i;
extern volatile int npad;
extern volatile int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < ret; i += 2) {
        mask &= !key[i];
        npad += mask;
    }
}
