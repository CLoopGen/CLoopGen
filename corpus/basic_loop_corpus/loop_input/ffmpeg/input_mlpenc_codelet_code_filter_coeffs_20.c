#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct FilterParams {
    uint8_t order;
    uint8_t shift;
    int32_t state[8];
    int coeff_bits;
    int coeff_shift;
} FilterParams;

FilterParams *fp;
int32_t *fcoeff;
int min;
int max;
int coeff_mask;
int order;

void init_vars() {
    fp = (FilterParams *)malloc(sizeof(FilterParams));
    fp->order = 65536; // Set order to ensure sufficient loop iterations
    fp->shift = 0;
    for (int i = 0; i < 8; i++) {
        fp->state[i] = 0;
    }
    fp->coeff_bits = 16;
    fp->coeff_shift = 0;

    fcoeff = (int32_t *)malloc(fp->order * sizeof(int32_t));

    // Initialize fcoeff with pseudo-random data to ensure meaningful comparisons
    for (int i = 0; i < fp->order; i++) {
        fcoeff[i] = rand() % 20000 - 10000; // Range: [-10000, 9999]
    }

    min =  INT32_MAX;
    max =  INT32_MIN;
    coeff_mask = 0;
    order = 0;
}