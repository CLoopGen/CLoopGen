#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *pix1;
extern  uint8_t *pix2;
extern int size;
extern uint64_t ssd;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < size; i += 2) {
        int d1 = pix1[i] - pix2[i];
        ssd += d1 * d1;
        if (i + 1 < size) {
            int d2 = pix1[i+1] - pix2[i+1];
            ssd += d2 * d2;
        }
    }
}
