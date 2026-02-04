#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *p1;
float *p2;
int stride2;
int length;
int i;

static float *internal_p1;
static float *internal_p2;

void init_vars() {
    length = 67108864; // 67M elements * sizeof(float) = ~256MB
    stride2 = 1;

    internal_p1 = (float *)aligned_alloc(32, length * sizeof(float));
    internal_p2 = (float *)aligned_alloc(32, length * sizeof(float));

    if (!internal_p1 || !internal_p2) {
        exit(1);
    }

    for (int idx = 0; idx < length; idx++) {
        internal_p1[idx] = (float)(idx * 1.5f);
    }

    p1 = internal_p1;
    p2 = internal_p2;
}