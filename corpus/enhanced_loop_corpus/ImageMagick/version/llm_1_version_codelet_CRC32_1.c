#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int crc_xor[256];
extern unsigned int j;
extern unsigned int alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t k;
    for (j = 0; j < 256; j++) {
        alpha = j;
        k = 0;
        for (; k < 8; k++) {
            if (alpha & 1) {
                alpha = 3988292384U ^ (alpha >> 1);
            } else {
                alpha = alpha >> 1;
            }
        }
        crc_xor[j] = alpha;
    }
}
