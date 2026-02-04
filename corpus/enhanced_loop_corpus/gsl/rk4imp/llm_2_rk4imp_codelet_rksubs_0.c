#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double y[];
extern  double fY[];
extern  double b[];
extern  size_t stage;
extern  size_t dim;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by swapping loop order for better spatial locality
    // This changes the access pattern of fY to be more cache-friendly by iterating consecutively over memory
    for (i = 0; i < dim; i++) {
        y[i] = 0.0;
    }
    for (j = 0; j < stage; j++) {
        double b_val = b[j];
        size_t base_idx = j * dim;
        for (i = 0; i < dim; i++) {
            y[i] += b_val * fY[base_idx + i];  // Now accessing fY in consecutive order
        }
    }
}
