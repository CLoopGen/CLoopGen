#include <stdio.h>

#include <inttypes.h>

extern unsigned char *key;
extern int ret;
extern int i;
extern volatile int npad;
extern volatile int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = ret - 1; i >= 0; i--) {
        mask &= !key[i];
        npad += mask;
    }
}
