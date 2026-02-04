#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 64; i += 2) {
        sum += ((block[i]) >= 0 ? (block[i]) : (-(block[i])));
        if (i + 1 < 64) {
            sum += ((block[i + 1]) >= 0 ? (block[i + 1]) : (-(block[i + 1])));
        }
    }
}
