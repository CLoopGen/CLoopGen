#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *histogram;
ssize_t i;
ssize_t end;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (about 131072 doubles)
    histogram = (double*)calloc(data_size, sizeof(double));
    
    // Initialize the first 256 elements with non-zero values
    for (ssize_t idx = 0; idx < 256; idx++) {
        histogram[idx] = (double)(idx + 1);
    }
    
    // Set a sentinel value to ensure loop stops at index 255
    // The loop counts down from 255, so we ensure only indices <=255 are relevant
    // No additional setup needed beyond ensuring memory is valid

    i = 0;
    end = -1;
}