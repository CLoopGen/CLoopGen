#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

extern gsl_histogram2d *h;
extern size_t i;
extern size_t j;
extern size_t k;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Introduce an auxiliary index array that stores precomputed linear indices
    // and access h->bin indirectly through this array to simulate irregular access.
    size_t idx[107 * 239];
    k = 0;
    // Precompute linear indices in row-major order (could be randomized or reordered for different patterns)
    for (size_t temp_i = 0; temp_i < 107; temp_i++) {
        for (size_t temp_j = 0; temp_j < 239; temp_j++) {
            idx[temp_i * 239 + temp_j] = temp_i * 239 + temp_j;
        }
    }
    // Now use indirect access via idx[]
    for (i = 0; i < 107; i++) {
        for (j = 0; j < 239; j++) {
            k++;
            if (h->bin[idx[i * 239 + j]] != (double)k) {
                status = 1;
            }
        }
    }
}
