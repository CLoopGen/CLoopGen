#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t len;
int k;
int16_t *tmp1;
int16_t *tmp2;
int16_t *tmp3;

static int16_t *arr1;
static int16_t *arr2;
static int16_t *arr3;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data (adjustable for ~0.01s runtime)
    len = data_size;

    arr1 = (int16_t*)aligned_alloc(32, (len + 1) * sizeof(int16_t));
    arr2 = (int16_t*)aligned_alloc(32, (len + 1) * sizeof(int16_t));
    arr3 = (int16_t*)aligned_alloc(32, (len + 1) * sizeof(int16_t));

    if (!arr1 || !arr2 || !arr3) {
        exit(1);
    }

    for (int i = 0; i <= len; i++) {
        arr1[i] = rand() % 1000;
        arr2[i] = rand() % 1000;
    }

    tmp1 = &arr1[len];
    tmp2 = &arr2[len];
    tmp3 = &arr3[0];
}