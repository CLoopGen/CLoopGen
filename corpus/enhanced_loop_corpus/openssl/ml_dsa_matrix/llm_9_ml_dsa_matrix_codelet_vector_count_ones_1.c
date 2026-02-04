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
    for (i = 0; i < v->num_poly && i < 128; i += 2) {
        for (j = 0; j < 256; j += 4) {
            count += v->poly[i].coeff[j] + v->poly[i].coeff[j+1] +
                     v->poly[i].coeff[j+2] + v->poly[i].coeff[j+3];
        }
        if (i + 1 < v->num_poly) {
            for (j = 0; j < 256; j++) {
                count += v->poly[i+1].coeff[j];
            }
        }
    }
}
