#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *values;
int count;
double mean;
int cut;
int x;

void init_vars() {
    count = 16777216; // ~16.7 million elements to achieve ~0.01 sec runtime
    cut = count / 8; // Ensure valid range: cut <= x < count - cut
    values = (double*)aligned_alloc(32, count * sizeof(double));
    if (!values) {
        exit(1);
    }
    for (int i = 0; i < count; i++) {
        values[i] = 1.5 + i * 0.1;
    }
    mean = 0.0;
    x = 0;
}