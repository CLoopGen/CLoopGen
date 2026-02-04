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
static VECTOR v_storage;
VECTOR *v = &v_storage;
int j;
size_t i;
size_t count;

void init_vars() {
    const size_t num_polys = 256; // 256 * 256 * sizeof(uint32_t) = 256 * 256 * 4 = 262144 bytes (~256KB)
    poly_array = (POLY *)calloc(num_polys, sizeof(POLY));
    if (!poly_array) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_polys; ++idx) {
        for (int jdx = 0; jdx < 256; ++jdx) {
            poly_array[idx].coeff[jdx] = (uint32_t)(idx + jdx);
        }
    }

    v->poly = poly_array;
    v->num_poly = num_polys;
    count = 0;
}