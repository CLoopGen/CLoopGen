#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *p;
int i0;
int i1;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB of float data (~256M bytes)
    p = (float*)aligned_alloc(32, data_size * sizeof(float));
    
    for (size_t idx = 0; idx < data_size; ++idx) {
        p[idx] = (float)(rand() % 1000) / 100.0f;
    }

    i0 = 2;  
    i1 = (data_size - 4);  

    if (i1 <= i0) {
        i0 = 0;
        i1 = 4;
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}