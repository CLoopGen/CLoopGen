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
    // Variant 1: Strided memory access pattern
    // Instead of accessing coeff[0], coeff[1], ... sequentially, access with a stride of 4
    // This changes spatial locality and may affect cache performance
    for (i = 0; i < v->num_poly; i++) {
        for (j = 0; j < 256; j += 4) {
            // Unroll the inner loop to maintain same operation count with stride
            count += v->poly[i].coeff[j];
            if (j + 1 < 256) count += v->poly[i].coeff[j + 1];
            if (j + 2 < 256) count += v->poly[i].coeff[j + 2];
            if (j + 3 < 256) count += v->poly[i].coeff[j + 3];
        }
    }
}
