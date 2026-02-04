#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *w;
int m;
int i;

void init_vars() {
    m = 26214400; // Size to target ~0.01 sec runtime (approx 100 MB of float data)
    w = (float*)aligned_alloc(32, (m + 1) * sizeof(float));
    if (!w) {
        exit(1);
    }
}