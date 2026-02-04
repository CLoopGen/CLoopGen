#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *res;
int32_t *smp;
int len;
int order;
int32_t *coefs;
int shift;
int big;
int i;

void init_vars() {
    const int data_size_mb = 64;
    const int element_size = sizeof(int32_t);
    const int total_elements = (data_size_mb * 1024 * 1024) / element_size;

    len = total_elements;
    shift = 15;
    big = 1;
    order = 32;

    smp = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    res = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    coefs = (int32_t*)aligned_alloc(32, 32 * sizeof(int32_t));

    for (int j = 0; j < len; ++j) {
        smp[j] = rand() % 1000 - 500;
    }
    for (int j = 0; j < 32; ++j) {
        coefs[j] = (rand() % 200) - 100;
    }
    for (int j = 0; j < len; ++j) {
        res[j] = 0;
    }

    i = 0;
}