#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int k;
extern unsigned int s[8];
extern unsigned int sx[8];
extern unsigned int sub_blocks;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < sub_blocks && k < 8; k++) {
        sx[k] = (s[k] & 15) + (s[k] >> 2) - (s[k] >> 3);
        s[k] >>= 5;
        s[k] += (sx[k] & 7) ^ 3;
    }
}
