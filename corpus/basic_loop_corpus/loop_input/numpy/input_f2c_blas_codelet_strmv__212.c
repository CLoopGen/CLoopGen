#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef int logical;

real *a;
real *x;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real temp;
logical nounit;

static real a_data[2048 * 2048];
static real x_data[2048];

void init_vars() {
    const int size = 2048;
    
    a_dim1 = size;
    i__1 = size;
    nounit = 1;
    
    a = a_data;
    x = x_data;
    
    for (int idx = 0; idx < size; ++idx) {
        x[idx] = (idx % 7 == 0) ? 0.0F : 1.0F + idx * 0.001F;
    }
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i + j * a_dim1] = sin(i * 0.01F) * cos(j * 0.01F) + 1.0F;
        }
    }
}