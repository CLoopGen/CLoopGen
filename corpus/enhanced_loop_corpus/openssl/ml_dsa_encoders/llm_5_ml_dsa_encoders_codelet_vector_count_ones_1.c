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
    count = 0;
    for (i = 0; i < v->num_poly; i++) {
        int early_exit = 0;
        for (j = 0; j < 256 && !early_exit; j++) {
            uint32_t val = v->poly[i].coeff[j];
            count += val;
            if (val > 1000) {
                early_exit = 1;
            }
        }
    }
}
