#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *t;
int w;
int h;
int i;

void init_vars() {
    w = 16384;
    h = 16384;
    size_t total_size = (size_t)w * h;
    
    t = (int*)aligned_alloc(32, total_size * sizeof(int));
    if (!t) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < total_size; idx++) {
        t[idx] = 1;
    }
}