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



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing coeff[j] in order, access with a stride of 4 (unrolled-like pattern)
    // Wrap around using modulo to ensure all elements are still accessed
    size_t stride = 4;
    for (i = 0; i < v->num_poly; i++) {
        for (j = 0; j < 256; j++) {
            size_t idx = (j * stride) % 256;  // Strided access with wrap-around
            count += v->poly[i].coeff[idx];
        }
    }
}
