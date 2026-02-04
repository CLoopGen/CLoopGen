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
    // Variant 2: Indirect Memory Access via Index Array
    // Use an explicitly defined index array to access coeff elements indirectly,
    // simulating scenarios with non-sequential or computed memory lookups.
    size_t indices[256];
    for (int idx = 0; idx < 256; idx++) {
        indices[idx] = 255 - idx; // Reverse order access
    }
    count = 0; // Reset count for correctness in testing
    for (i = 0; i < v->num_poly; i++) {
        for (j = 0; j < 256; j++) {
            count += v->poly[i].coeff[indices[j]]; // Indirect access using precomputed indices
        }
    }
}
