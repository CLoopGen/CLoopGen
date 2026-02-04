#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef float real_t;

__attribute__((aligned(64))) real_t flat_2d_array[65536];
__attribute__((aligned(64))) real_t a[32000];
real_t *restrict xx;

void init_vars() {
    // Initialize xx to point to a dynamically allocated and aligned array of size 32000
    posix_memalign((void**)&xx, 64, 32000 * sizeof(real_t));
    
    // Initialize arrays with sample data to ensure meaningful computation
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i * 2);
        xx[i] = (real_t)(i * 3);
    }
    
    // Initialize flat_2d_array, especially the first element which may be used
    for (int i = 0; i < 65536; i++) {
        flat_2d_array[i] = (real_t)1.0;
    }
}