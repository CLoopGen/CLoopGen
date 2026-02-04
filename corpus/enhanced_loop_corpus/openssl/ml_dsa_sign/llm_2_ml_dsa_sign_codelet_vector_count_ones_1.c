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
    // Instead of accessing elements in row-major order, traverse with a stride
    // Here we access every 4th element in each polynomial coefficient array, then cover the rest in subsequent passes
    count = 0;
    for (int step = 0; step < 4; step++) {
        for (i = 0; i < v->num_poly; i++) {
            for (j = step; j < 256; j += 4) {
                count += v->poly[i].coeff[j];
            }
        }
    }
}
