#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int crc_xor[256];
extern unsigned int j;
extern unsigned int alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 256; j++) {
    ssize_t k = 0;
    alpha = j;
    for (; k < 8; k++) {
        alpha = alpha >> 1;
        if ((j >> k) & 1) {
            alpha ^= 3988292384U << (7 - k);
        }
    }
    crc_xor[j] = alpha;
}
}
