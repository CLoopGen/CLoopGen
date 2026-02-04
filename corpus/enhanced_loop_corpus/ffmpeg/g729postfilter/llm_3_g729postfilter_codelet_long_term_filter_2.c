#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *residual;
extern int subframe_size;
extern int i;
extern int16_t shift;
extern int16_t sig_scaled[192];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2
    // This variant processes elements in a strided pattern, accessing every second element first
    int bound = subframe_size + (143 + 8 + 1);
    // First pass: even indices
    for (i = 0; i < bound; i += 2) {
        sig_scaled[i] = residual[i] >> shift;
    }
    // Second pass: odd indices
    for (i = 1; i < bound; i += 2) {
        sig_scaled[i] = residual[i] >> shift;
    }
}
