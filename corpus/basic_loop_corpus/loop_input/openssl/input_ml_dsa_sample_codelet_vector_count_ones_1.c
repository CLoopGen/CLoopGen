#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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
static VECTOR v_instance;
VECTOR *v = &v_instance;
int j;
size_t i;
size_t count;

void init_vars() {
    const size_t total_data_size = 1024 * 1024; // Aim for ~1MB of data
    const size_t elements_per_poly = 256;
    const size_t bytes_per_poly = elements_per_poly * sizeof(uint32_t);
    v->num_poly = total_data_size / bytes_per_poly;
    if (v->num_poly == 0) v->num_poly = 1;

    poly_array = calloc(v->num_poly, sizeof(POLY));
    if (!poly_array) {
        v->poly = NULL;
        return;
    }

    v->poly = poly_array;

    for (size_t idx = 0; idx < v->num_poly; idx++) {
        for (int jdx = 0; jdx < 256; jdx++) {
            poly_array[idx].coeff[jdx] = (uint32_t)(idx + jdx);
        }
    }

    i = 0;
    j = 0;
    count = 0;
}