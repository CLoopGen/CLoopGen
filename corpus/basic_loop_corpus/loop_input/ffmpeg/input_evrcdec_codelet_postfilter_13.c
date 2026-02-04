#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *in;
int length;
float sum2;
int i;

void init_vars() {
    length = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
    in = (float *)malloc(length * sizeof(float));
    if (!in) {
        exit(1);
    }
    for (int j = 0; j < length; j++) {
        in[j] = 1.0f; // Simple initialization to avoid undefined behavior
    }
    sum2 = 0.0f;
    i = 0;
}