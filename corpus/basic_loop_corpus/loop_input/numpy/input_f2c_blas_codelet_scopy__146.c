#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef float real;
typedef int integer;

real *sx = NULL;
real *sy = NULL;
integer i__1;
integer i__;
integer mp1;

static real *alloc_aligned_real_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(real)) != 0) {
        return NULL;
    }
    return (real *)ptr;
}

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // 128 MB of data
    const size_t num_elements = total_size / sizeof(real);
    
    sx = alloc_aligned_real_array(num_elements);
    sy = alloc_aligned_real_array(num_elements);
    
    if (!sx || !sy) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    for (size_t i = 0; i < num_elements; ++i) {
        sx[i] = (real)(i % 1000) / 100.0f;
        sy[i] = 0.0f;
    }
    
    mp1 = 0;
    i__1 = (integer)(num_elements - 7);
}