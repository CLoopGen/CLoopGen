#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *t;
integer t_dim1;
integer i__1;
integer j;

void init_vars() {
    // Set dimensions to ensure ~0.01s runtime: aim for moderate memory access
    // The loop runs i__1 iterations, each writing to two elements in t.
    // We'll size t as a 2D array with square-like dimensions to match t[j + 2 + j*t_dim1]
    
    i__1 = 8000;  // Number of iterations (~8k to stay in cache but take time)
    t_dim1 = 16384;  // Leading dimension, allows safe indexing with j*t_dim1 + offset

    // Allocate total size: at least (i__1 + 3) + (i__1 + 3)*t_dim1, but we simplify
    // Max index: j + 3 + j * t_dim1 where j = i__1 => i__1 + 3 + i__1 * t_dim1
    // So we need: size >= i__1 + 3 + i__1 * t_dim1 + 1
    size_t total_size = (i__1 + 4) * (t_dim1 + 1);
    
    t = (real*)calloc(total_size, sizeof(real));
    if (!t) {
        exit(1);
    }
}