#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int16_t *in;
extern int num_vect;
extern  uint8_t line_len[2];
extern int length_div;
extern int i;
extern int j;
extern int cont;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Fixed Stride
    // Use a fixed strided access pattern on input array to simulate irregular but predictable memory access
    // This variant precomputes effective length and uses a constant stride regardless of conditionals
    int max_len = (line_len[0] > line_len[1]) ? line_len[0] : line_len[1];
    int stride = num_vect;
    int base_offset;
    for (i = 0; i < num_vect; i++) {
        base_offset = i;
        for (j = 0; j < max_len; j++) {
            int effective_index = base_offset + j * stride;
            if (j < line_len[i >= length_div]) {
                out[cont++] = in[effective_index];
            }
        }
    }
}
