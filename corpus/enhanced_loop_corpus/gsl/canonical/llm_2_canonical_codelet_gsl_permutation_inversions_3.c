#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  gsl_permutation *p;
extern size_t count;
extern size_t i;
extern size_t j;
extern  size_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements, we introduce a stride of 2,
    // and handle boundary conditions to ensure we don't exceed array size.
    // We still maintain the same logical comparison but access memory in strided manner.
    size_t stride = 2;
    for (i = 0; i < size - 1; i += stride) {
        for (j = i + stride; j < size; j += stride) {
            if (p->data[i] > p->data[j]) {
                count++;
            }
        }
        // Handle non-strided elements within the stride range to preserve logic
        for (size_t ii = i + 1; ii < i + stride && ii < size - 1; ii++) {
            for (size_t jj = ii + 1; jj < size; jj++) {
                if (p->data[ii] > p->data[jj]) {
                    count++;
                }
            }
        }
    }
}
