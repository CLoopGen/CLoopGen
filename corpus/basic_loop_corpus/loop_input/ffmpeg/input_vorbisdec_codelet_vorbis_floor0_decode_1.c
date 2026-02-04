#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *lsp;
int order;
int j;
float p;
float q;
float two_cos_w;

void init_vars() {
    two_cos_w = 1.5f;
    p = 1.0f;
    q = 1.0f;
    order = 1 << 24; // Approximately 16.7 million elements, adjust for ~0.01 sec runtime
    lsp = (float*)aligned_alloc(32, order * sizeof(float));
    if (!lsp) {
        exit(1);
    }
    for (int i = 0; i < order; i++) {
        lsp[i] = (float)(i % 100) + 2.0f;
    }
}