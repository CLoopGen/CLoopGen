#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int32_t *data;
int len;
double *w_data;
int i;
int n2;
double w;
double c;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(int32_t); // ~256 MB of int32_t data
    n2 = len / 2;

    data = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    w_data = (double*)aligned_alloc(32, len * sizeof(double));

    if (!data || !w_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        data[j] = rand() % 1000;
        w_data[j] = 0.0;
    }

    c = 100.0;
    w = 0.0;
    i = 0;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}