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
    // Instead of accessing coefficients in row-major order (j from 0 to 255),
    // we access them with a stride of 4, unrolling the inner loop to maintain correctness.
    count = 0;
    for (i = 0; i < v->num_poly; i++) {
        for (j = 0; j < 64; j++) {  // Process 4 elements per iteration
            count += v->poly[i].coeff[j * 4 + 0];
            count += v->poly[i].coeff[j * 4 + 1];
            count += v->poly[i].coeff[j * 4 + 2];
            count += v->poly[i].coeff[j * 4 + 3];
        }
    }
}
