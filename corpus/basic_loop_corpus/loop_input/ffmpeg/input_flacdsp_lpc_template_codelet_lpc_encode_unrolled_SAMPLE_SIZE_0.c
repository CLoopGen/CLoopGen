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

    smp = (int32_t*)aligned_alloc(32, sizeof(int32_t) * len);
    res = (int32_t*)aligned_alloc(32, sizeof(int32_t) * len);
    coefs = (int32_t*)aligned_alloc(32, sizeof(int32_t) * 32);

    for (int j = 0; j < len; j++) {
        smp[j] = (int32_t)(rand() % 65536 - 32768);
    }
    for (int j = 0; j < 32; j++) {
        coefs[j] = (int32_t)(rand() % 512 - 256);
    }
}
