#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern  uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, unrolled by factor 2)
    // Accesses are now in a strided pattern, reducing total iterations but covering same range
    for (i = 0; i < 8; i++) {
        out[2 * i]     = in[15 - 2 * i];
        out[2 * i + 1] = in[15 - (2 * i + 1)];
    }
}
