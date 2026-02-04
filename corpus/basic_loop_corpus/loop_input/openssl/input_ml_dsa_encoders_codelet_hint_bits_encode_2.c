#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct poly_st {
    uint32_t coeff[256];
};

typedef struct poly_st POLY;

uint32_t omega = 1024;
int i = 0;
int j = 0;
int k = 256;
size_t coeff_index = 0;

POLY *p;
uint8_t *data;

void init_vars() {
    // Allocate and initialize POLY array
    p = (POLY *)calloc(k, sizeof(POLY));
    if (!p) {
        fprintf(stderr, "Failed to allocate memory for p\n");
        exit(1);
    }

    // Initialize each POLY's coeff with sparse non-zero values to simulate realistic input
    for (int idx = 0; idx < k; idx++) {
        for (int c = 0; c < 256; c++) {
            // Set ~20% of coefficients to non-zero
            p[idx].coeff[c] = (c % 5 == 0) ? (c * 17 + idx) : 0;
        }
    }

    // Allocate data buffer: need at least omega + k + expected non-zero indices
    size_t data_size = omega + k + (k * 256 * 0.2) + 1024;  // extra headroom
    data = (uint8_t *)malloc(data_size);
    if (!data) {
        fprintf(stderr, "Failed to allocate memory for data\n");
        exit(1);
    }
    memset(data, 0, data_size);

    // Reset global index
    coeff_index = 0;
}