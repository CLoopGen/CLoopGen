#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern int b;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with indirect indexing using a pointer
    // Introduce a pointer to create indirect and strided writes
    char *ptr = bits;
    for (b = 0; b < width; b += 8) {
        uint32_t base_shift = b;
        for (i = 0; i < 8; i++) {
            ptr[i] = (value >> (base_shift + i)) & 1 ? '1' : '0';
        }
        ptr += 8; // Move pointer forward by stride of 8
    }
}
