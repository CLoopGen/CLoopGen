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
    // Variant 2: Consecutive Flat Array Access via Pointer
    // Flatten the 2D-like access into a single sequential scan using pointer arithmetic
    // This improves spatial locality and enables better vectorization
    uint32_t *base = &(v->poly[0].coeff[0]);
    size_t total_elements = v->num_poly * 256;
    for (size_t idx = 0; idx < total_elements; idx++) {
        count += base[idx];
    }
}
