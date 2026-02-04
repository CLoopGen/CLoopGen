#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int16_t dc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed and non-unit stride pattern
    int16_t *b = block;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            b[j * 4] = dc;  // Transposed access pattern: treating block as column-major
        }
        b++;  // Move to next row base
    }
}
