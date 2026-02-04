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
    // Variant 2: Strided memory access on input array (stride of 2, wrapping logically within bounds)
    for (i = 0; i < 4; i++) {
        int idx = (3 - ((i * 2) % 4)); // Generate access pattern: 3, 1, 3, 1 -> clamped to valid indices
        pred += (int64_t)input[idx] * coeff[i];
    }
}
