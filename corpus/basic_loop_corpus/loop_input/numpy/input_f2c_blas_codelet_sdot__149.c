#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef float real;
typedef int integer;

real *sx;
real *sy;
integer i__1;
integer i__;
integer mp1;
real stemp;

static real sx_data[64000000];
static real sy_data[64000000];

void init_vars() {
    const size_t data_size = 64000000;
    const double target_time_seconds = 0.01;
    const double avg_ops_per_element = 10;
    const double estimated_throughput_gops = 3.0;
    
    size_t effective_size = (size_t)(target_time_seconds * estimated_throughput_gops * 1e9 / avg_ops_per_element);
    size_t used_size = effective_size > data_size ? data_size : (effective_size < 1000 ? 1000 : effective_size);

    for (size_t i = 0; i < used_size; ++i) {
        sx_data[i] = (real)(i % 123) * 0.01f;
        sy_data[i] = (real)(i % 456) * 0.02f;
    }

    sx = sx_data;
    sy = sy_data;
    mp1 = 1;
    i__1 = (integer)(used_size - 8);
    i__ = mp1;
    stemp = 1.23f;
}