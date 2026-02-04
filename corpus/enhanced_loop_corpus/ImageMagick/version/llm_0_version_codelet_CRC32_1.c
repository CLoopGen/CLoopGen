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
        ssize_t k;
        alpha = j;
        for (k = 0; k < 8; k++) {
            alpha = (alpha & 1) ? (3988292384U ^ (alpha >> 1)) : (alpha >> 1);
        }
        crc_xor[j] = alpha;
    }
}
