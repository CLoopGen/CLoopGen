#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *n;
real *z__;
real *delta;
integer i__1;
integer j;
real phi;
real dphi;
real temp;
real erretm;

static real *z__buf;
static real *delta_buf;
static const size_t data_size = 65536; // ~512KB of data (65536 * 4 * 2)

void init_vars() {
    z__buf = (real*)calloc(data_size, sizeof(real));
    delta_buf = (real*)calloc(data_size, sizeof(real));
    
    if (!z__buf || !delta_buf) {
        exit(1);
    }
    
    for (size_t i = 0; i < data_size; ++i) {
        z__buf[i] = (real)(i + 1) * 0.5f;
        delta_buf[i] = (real)(i + 1) * 2.0f + 1.0f;
    }
    
    n = (integer*)malloc(sizeof(integer));
    *n = (integer)(data_size - 1);
    i__1 = 1;
    
    z__ = z__buf;
    delta = delta_buf;
    
    phi = 0.0f;
    dphi = 0.0f;
    temp = 0.0f;
    erretm = 0.0f;
}