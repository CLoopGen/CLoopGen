#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *q;
integer q_dim1;
integer i__1;
integer i__;
integer ktemp;

void init_vars() {
    q_dim1 = 10000;
    i__1 = 5000;
    ktemp = 2;
    
    size_t total_size = (i__1 + 1) * (ktemp + 1) * sizeof(real);
    if (total_size < 1024*1024) {
        total_size = 1024*1024; 
        q_dim1 = (total_size / sizeof(real)) / (ktemp + 1);
        i__1 = q_dim1 / 2;
    }

    q = (real*)calloc(q_dim1 * (ktemp + 1) + i__1 + 1, sizeof(real));
    if (!q) {
        exit(1);
    }
}