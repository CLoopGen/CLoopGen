#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *p1;
int stride1;
float *p2;
int length;
int i;

static float *arr1;
static float *arr2;

void init_vars() {
    length = 67108864; // 67M elements, ~256MB for float array
    stride1 = 1;

    arr1 = (float *)aligned_alloc(32, length * sizeof(float));
    arr2 = (float *)aligned_alloc(32, length * sizeof(float));

    if (!arr1 || !arr2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < length; j++) {
        arr1[j] = (float)(j * 2);
        arr2[j] = 0.0f;
    }

    p1 = arr1;
    p2 = arr2;
}