#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float wmavoice_std_codebook[1000] = {0};

int size = 500;

float *excitation = NULL;

float gain = 1.5f;

int n = 0;

int r_idx = 0;

void init_vars() {
    const int data_size = 134217728; // ~128MB to achieve ~0.01s runtime on modern CPU
    size = 1000 - r_idx; // Ensure no out-of-bounds access: r_idx + n < 1000
    if (size <= 0) {
        size = 1;
        r_idx = 0;
    }
    excitation = (float *)aligned_alloc(32, data_size);
    if (!excitation) {
        exit(1);
    }
    for (int i = 0; i < data_size / sizeof(float); ++i) {
        excitation[i] = 0.0f;
    }
    for (int i = 0; i < 1000; ++i) {
        wmavoice_std_codebook[i] = (float)(i % 100) * 0.01f;
    }
    gain = 1.2f;
    r_idx = 500;
}