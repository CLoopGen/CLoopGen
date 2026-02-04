#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *input;
extern int i;
extern  int16_t *coeff;
extern int64_t pred;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride of 2 (wrapped via modulo indexing)
    for (i = 0; i < 4; i++) {
        int stride = 2;
        int idx_input = (0 + i * stride) % 4; // Generates sequence: 0,2,0,2 (mod 4)
        int idx_coeff = (3 - i); // Maintain decreasing coeff index to keep semantic similarity
        pred += (int64_t)input[3 - idx_input] * coeff[idx_coeff]; // Adjust input base offset to preserve data flow intent
    }
}
