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
    for (k = 0; k < (sub_blocks >> 1); k++) {
        unsigned int temp1 = s[k] & 15;
        unsigned int temp2 = s[k + 4] & 15;
        sx[k] = temp1;
        sx[k + 4] = temp2;
        s[k] >>= 4;
        s[k + 4] >>= 4;
    }
}
