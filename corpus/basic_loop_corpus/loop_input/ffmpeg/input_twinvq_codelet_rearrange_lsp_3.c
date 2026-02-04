#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int order;
float *lsp;
float min_dist;
int i;
float min_dist2;

void init_vars() {
    order = 1 << 20;
    min_dist = 0.01f;
    min_dist2 = 0.005f;
    lsp = (float*)aligned_alloc(32, order * sizeof(float));
    for (int idx = 0; idx < order; idx++) {
        lsp[idx] = ((float)rand() / RAND_MAX) * 10.0f;
    }
}