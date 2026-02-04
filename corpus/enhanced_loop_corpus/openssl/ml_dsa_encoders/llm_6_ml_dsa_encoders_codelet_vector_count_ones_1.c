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
    size_t i;
    int j;
    uint64_t local_count = 0;
    for (i = 0; i < v->num_poly; i++) {
        uint32_t *coeffs = v->poly[i].coeff;
        for (j = 0; j < 256; j++) {
            local_count += coeffs[j];
        }
    }
    count = local_count;
}
