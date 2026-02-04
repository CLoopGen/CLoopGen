#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *Y;
int incY;
int i;
int lenY;
int iy;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB
    const size_t num_doubles = data_size / sizeof(double);
    
    double *y_ptr = (double *)aligned_alloc(32, data_size);
    if (!y_ptr) {
        exit(1);
    }

    Y = y_ptr;
    lenY = num_doubles / 2; 
    incY = 1;
    iy = 0;
}