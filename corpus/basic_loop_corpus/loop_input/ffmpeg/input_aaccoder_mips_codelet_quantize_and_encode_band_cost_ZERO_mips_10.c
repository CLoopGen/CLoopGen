#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
int size;
int i;

void init_vars() {
    size = 67108864; // 64M floats = 256MB, allows ~0.01s execution with optimization
    out = (float*)aligned_alloc(32, size * sizeof(float));
    if (!out) {
        exit(1);
    }
}