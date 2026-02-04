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
    // Variant 2: Reverse sequential access – process array from end to start
    // This changes the memory access pattern to descending order
    unsigned int i;
    for (i = sub_blocks; i != 0; i--) {
        unsigned int k_rev = i - 1;
        sx[k_rev] = s[k_rev] & 15;
        s[k_rev] >>= 4;
    }
}
