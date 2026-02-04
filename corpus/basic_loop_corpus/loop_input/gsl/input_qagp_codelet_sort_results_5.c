#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

size_t i;
double *elist;
size_t *order;
size_t nint;

static double elist_data[131072];
static size_t order_data[131072];

void init_vars() {
    nint = 131072;
    
    elist = elist_data;
    order = order_data;
    
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&nint));
    
    for (size_t idx = 0; idx < nint; idx++) {
        elist[idx] = (double)(rand() % 100000) / 100.0;
        order[idx] = idx;
    }
    
    for (size_t idx = 0; idx < nint; idx++) {
        size_t j = idx + rand() % (nint - idx);
        size_t temp = order[idx];
        order[idx] = order[j];
        order[j] = temp;
    }
}