#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float *vec1;
float *vec2;
int n;
int x;

void init_vars() {
    n = 67108864;  // ~256MB total (two arrays of float, 4 bytes each -> 67M elements gives ~256MB)
    
    vec1 = (float*)aligned_alloc(32, n * sizeof(float));
    vec2 = (float*)aligned_alloc(32, n * sizeof(float));

    if (!vec1 || !vec2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        vec2[i] = (float)(i % 1000);
    }

    for (int i = 0; i < n; i++) {
        vec1[i] = 0.0f;
    }
}