#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *n;
real *a;
real *x;
integer a_dim1;
integer i__;
integer j;
real temp;
logical nounit;

static real a_data[2048 * 2048];
static real x_data[2048];

void init_vars() {
    const int size = 2048;

    n = (integer*)malloc(sizeof(integer));
    *n = size;

    a = a_data;
    x = x_data;
    a_dim1 = size;

    nounit = 1;

    for (int idx = 0; idx < size; ++idx) {
        x[idx] = 1.0f + (real)(idx % 7);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i + j * a_dim1] = (real)((i + j) % 5 + 1);
        }
    }
}