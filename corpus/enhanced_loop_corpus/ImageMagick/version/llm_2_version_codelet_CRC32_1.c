#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int crc_xor[256];
extern unsigned int j;
extern unsigned int alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access in reverse order with stride of 2
    for (j = 254; j < 256; j -= 2) {
        ssize_t k;
        alpha = j;
        for (k = 0; k < 8; k++) {
            alpha = (alpha & 1) ? (3988292384U ^ (alpha >> 1)) : (alpha >> 1);
        }
        crc_xor[j] = alpha;

        // Handle next index in stride
        if (j > 0) {
            alpha = j - 1;
            for (k = 0; k < 8; k++) {
                alpha = (alpha & 1) ? (3988292384U ^ (alpha >> 1)) : (alpha >> 1);
            }
            crc_xor[j - 1] = alpha;
        }
    }
}
