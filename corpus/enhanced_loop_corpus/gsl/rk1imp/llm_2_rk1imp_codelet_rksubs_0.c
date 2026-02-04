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
    // Variant 1: Consecutive memory access by swapping loop order for spatial locality
    // This improves cache performance by accessing fY in a stride-1 pattern
    for (j = 0; j < stage; j++) {
        double bj = b[j];  // Load once per j
        size_t offset = j * dim;
        for (i = 0; i < dim; i++) {
            y[i] += bj * fY[offset + i];
        }
    }
    // Initialize y to zero before accumulation
    for (i = 0; i < dim; i++) {
        y[i] = 0.0;
    }
}
