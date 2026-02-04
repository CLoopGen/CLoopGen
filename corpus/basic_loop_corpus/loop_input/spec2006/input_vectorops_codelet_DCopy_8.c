#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

double *vec1;
double *vec2;
int n;
int x;

void init_vars() {
    n = 134217728 / sizeof(double);  // ~1073741824 bytes total for two arrays -> ~1GB, ensures ~0.01s on modern CPU
    vec1 = (double*)malloc(n * sizeof(double));
    vec2 = (double*)malloc(n * sizeof(double));

    if (!vec1 || !vec2) {
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        vec2[i] = (double)(i & 0xFF);
    }

    x = 0;
}