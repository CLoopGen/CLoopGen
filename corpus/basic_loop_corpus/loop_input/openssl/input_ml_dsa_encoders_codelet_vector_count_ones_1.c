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

VECTOR *v;
int j;
size_t i;
size_t count;

static POLY *poly_array;
static VECTOR vector_instance;

void init_vars() {
    const size_t total_data_size = 1024 * 128; // Aim for ~128KB of data
    const size_t elements_per_poly = 256;
    const size_t data_per_poly = elements_per_poly * sizeof(uint32_t);
    size_t num_poly = total_data_size / data_per_poly;

    if (num_poly == 0) num_poly = 1;

    poly_array = calloc(num_poly, sizeof(POLY));
    if (!poly_array) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_poly; idx++) {
        for (int jdx = 0; jdx < 256; jdx++) {
            poly_array[idx].coeff[jdx] = (uint32_t)(idx + jdx);
        }
    }

    vector_instance.poly = poly_array;
    vector_instance.num_poly = num_poly;
    v = &vector_instance;
    j = 0;
    i = 0;
    count = 0;
}