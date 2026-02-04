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
    for (i = 0; i < v->num_poly && i < 128; i++) {
        for (j = 0; j < 256; j += 4) {
            count += v->poly[i].coeff[j];
            if (j + 1 < 256) count += v->poly[i].coeff[j + 1];
            if (j + 2 < 256) count += v->poly[i].coeff[j + 2];
            if (j + 3 < 256) count += v->poly[i].coeff[j + 3];
        }
    }
}
