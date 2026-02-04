#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *i__;
real *d__;
real *delta;
integer i__1;
integer j;
real tau;

static size_t data_size = 0;

void init_vars() {
    const double target_time = 0.01; 
    const double ops_per_byte = 3.0; 
    const double cpu_speed_gops = 3.0; 
    const double bytes_per_element = sizeof(real);
    
    data_size = (size_t)((target_time * cpu_speed_gops * 1e9) / ops_per_byte);
    if (data_size == 0) data_size = 1;
    data_size = (data_size + 3) & ~((size_t)3); 

    d__ = (real*)aligned_alloc(32, (data_size + 1) * sizeof(real));
    delta = (real*)aligned_alloc(32, (data_size + 1) * sizeof(real));
    i__ = (integer*)malloc(sizeof(integer));

    if (!d__ || !delta || !i__) {
        free(d__); free(delta); free(i__);
        exit(1);
    }

    for (size_t idx = 1; idx <= data_size; ++idx) {
        d__[idx] = (real)(sin(idx * 0.01) * 100.0);
    }

    *i__ = (integer)(data_size * 0.8);
    i__1 = (integer)data_size;
    if (*i__ >= 1 && *i__ <= i__1) {
        tau = 1.5f;
    } else {
        tau = 0.0f;
    }

    j = 0;
}