#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *p;
int i0;
int i1;
int i;

static int *p_internal;
static size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime

void init_vars() {
    p_internal = aligned_alloc(32, data_size);
    
    if (!p_internal) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < data_size / sizeof(int); idx++) {
        p_internal[idx] = rand() % 1000;
    }
    
    p = p_internal;
    i0 = 2;
    i1 = (data_size / sizeof(int)) - 2;
}