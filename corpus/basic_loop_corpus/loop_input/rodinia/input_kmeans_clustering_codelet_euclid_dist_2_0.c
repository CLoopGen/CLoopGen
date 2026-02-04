#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *pt1;
float *pt2;
int numdims;
int i;
float ans;

void init_vars() {
    size_t data_size = 1 << 24; // Approximately 16.7 million floats (~64 MB)
    numdims = data_size;
    pt1 = (float *)aligned_alloc(32, numdims * sizeof(float));
    pt2 = (float *)aligned_alloc(32, numdims * sizeof(float));

    for (int j = 0; j < numdims; j++) {
        pt1[j] = 1.0f + (j % 100);
        pt2[j] = 2.0f + (j % 100);
    }

    i = 0;
    ans = 0.0f;
}