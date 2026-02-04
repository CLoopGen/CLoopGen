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
    size_t data_size = 64 * 1024 * 1024; // ~256 MB for two float arrays (each float is 4 bytes)
    numdims = data_size / sizeof(float); // number of float elements per array

    pt1 = (float*)aligned_alloc(32, data_size);
    pt2 = (float*)aligned_alloc(32, data_size);

    if (!pt1 || !pt2) {
        exit(1);
    }

    for (int j = 0; j < numdims; j++) {
        pt1[j] = 1.0f + j * 0.0001f;
        pt2[j] = 2.0f + j * 0.0001f;
    }

    i = 0;
    ans = 0.0f;
}