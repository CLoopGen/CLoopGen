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
if (sub_blocks > 0) {
    for (k = 0; k < sub_blocks; k += 2) {
        sx[k] = s[k] & 15;
        s[k] >>= 4;
        if (k + 1 < sub_blocks) {
            sx[k + 1] = s[k + 1] & 15;
            s[k + 1] >>= 4;
        }
    }
}
}
