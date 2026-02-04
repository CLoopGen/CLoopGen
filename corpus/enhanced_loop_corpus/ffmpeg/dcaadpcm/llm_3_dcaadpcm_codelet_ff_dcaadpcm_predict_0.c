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
    // Variant 2: Strided memory access on coefficients (stride of 2, wrapping via modulo)
    // Simulates irregular but deterministic access pattern on coeff array.
    // We maintain total 4 iterations but access coeff with a stride, using modulo to stay in bounds.
    for (i = 0; i < 4; i++) {
        int idx = (i * 2) % 4;  // Stride of 2 over coeff: indices 0,2,0,2
        pred += (int64_t)input[4 - 1 - i] * coeff[idx];
    }
}
