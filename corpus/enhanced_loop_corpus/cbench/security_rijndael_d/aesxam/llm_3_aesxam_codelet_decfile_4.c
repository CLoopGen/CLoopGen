#include <stdio.h>

#include <inttypes.h>

extern char outbuf[16];
extern char *bp2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index map (reverse order traversal)
    int indices[16] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    for (i = 0; i < 16; ++i) {
        int idx = indices[i];
        outbuf[idx] ^= bp2[idx];
    }
}
