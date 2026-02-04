#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float *src;
int tab_step;
int order0;
float *out;
double *tab;
int i;
int j;

void init_vars() {
    order0 = 256;
    tab_step = 1024;
    
    src = (float*)aligned_alloc(32, order0 * sizeof(float));
    out = (float*)aligned_alloc(32, tab_step * sizeof(float));
    tab = (double*)aligned_alloc(32, order0 * tab_step * sizeof(double));
    
    for (int idx = 0; idx < order0; idx++) {
        src[idx] = (float)(idx % 128) / 64.0f;
    }
    
    for (int idx = 0; idx < tab_step; idx++) {
        out[idx] = (float)(idx % 256) / 128.0f;
    }
    
    for (int idx = 0; idx < order0 * tab_step; idx++) {
        tab[idx] = (double)(rand() % 100) / 50.0;
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}