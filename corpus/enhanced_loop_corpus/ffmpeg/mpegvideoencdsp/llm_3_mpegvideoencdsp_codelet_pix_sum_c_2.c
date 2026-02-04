#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process one column at a time instead of row blocks
    uint8_t *base = pix;
    for (j = 0; j < 8; j++) {  // Process 8 columns in strided manner
        for (i = 0; i < 16; i++) {
            s += base[i * line_size + j + 0];
            s += base[i * line_size + j + 8];
        }
    }
    // Advance pix pointer as in original to maintain semantic consistency
    pix = base + 16 * line_size;
}
