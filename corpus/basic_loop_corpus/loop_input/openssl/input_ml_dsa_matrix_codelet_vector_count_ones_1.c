#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct poly_st {
    uint32_t coeff[256];
};

typedef struct poly_st POLY;

struct vector_st {
    POLY *poly;
    size_t num_poly;
};

typedef struct vector_st VECTOR;

static POLY *poly_array;
static VECTOR v_storage;
VECTOR *v = &v_storage;
int j;
size_t i;
size_t count;

void init_vars() {
    const size_t total_data_size = 1024 * 1024; 
    const size_t elements_needed = total_data_size / sizeof(uint32_t);
    const size_t coeffs_per_poly = 256;
    v->num_poly = elements_needed / coeffs_per_poly;

    poly_array = (POLY *)calloc(v->num_poly, sizeof(POLY));
    if (!poly_array) {
        exit(1);
    }

    v->poly = poly_array;

    for (size_t idx = 0; idx < v->num_poly; idx++) {
        for (int c = 0; c < 256; c++) {
            poly_array[idx].coeff[c] = (uint32_t)(idx + c);
        }
    }

    i = 0;
    j = 0;
    count = 0;
}