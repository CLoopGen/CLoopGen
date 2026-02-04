#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float *histogram1;
float *histogram2;
unsigned int *cchange;
size_t hsize;
int i;

void init_vars() {
    hsize = 1 << 20; // 1 million elements, approx 4MB per array -> total ~12MB

    histogram1 = (float*)aligned_alloc(32, hsize * sizeof(float));
    histogram2 = (float*)aligned_alloc(32, hsize * sizeof(float));
    cchange = (unsigned int*)aligned_alloc(32, hsize * sizeof(unsigned int));

    if (!histogram1 || !histogram2 || !cchange) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < hsize; idx++) {
        histogram1[idx] = (float)(rand() % 1000);
        histogram2[idx] = (float)(rand() % 1000);
    }
}