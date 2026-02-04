#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *vec;
int n = 67108864;  // Approximately 256MB of float data (67M elements)
int x;

void init_vars() {
    vec = (float*)aligned_alloc(32, n * sizeof(float));
    if (!vec) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}