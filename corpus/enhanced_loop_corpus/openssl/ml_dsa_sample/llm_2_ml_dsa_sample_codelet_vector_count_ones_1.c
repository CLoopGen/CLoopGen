#include <stdio.h>

#include <inttypes.h>

struct poly_st {
    uint32_t coeff[256];
};


typedef struct poly_st POLY;

struct vector_st {
    POLY *poly;
    size_t num_poly;
};


typedef struct vector_st VECTOR;

extern  VECTOR *v;
extern int j;
extern size_t i;
extern size_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing elements in row-major order, traverse with a stride of 64 across coefficients,
    // creating a strided access pattern that may affect cache performance.
    size_t stride = 64;
    count = 0; // Reset count for correctness in testing
    for (i = 0; i < v->num_poly; i++) {
        for (j = 0; j < 256; j += stride) {
            for (int s = 0; s < stride && (j + s) < 256; s++) {
                count += v->poly[i].coeff[j + s];
            }
        }
    }
}
