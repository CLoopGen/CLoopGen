#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *a;
float *b;
int length;
float sum;
int i;

void init_vars() {
    length = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
    a = (float*)malloc(length * sizeof(float));
    b = (float*)malloc(length * sizeof(float));
    if (!a || !b) {
        exit(1);
    }
    for (int j = 0; j < length; j++) {
        a[j] = 1.0f;
        b[j] = 2.0f;
    }
    sum = 0.0f;
    i = 0;
}