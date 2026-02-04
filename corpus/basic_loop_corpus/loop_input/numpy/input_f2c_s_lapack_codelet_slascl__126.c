#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__5;
integer i__4;
integer i__;
integer j;
integer k1;
integer k2;
integer k3;
integer k4;
real mul;

void init_vars() {
    i__1 = 1000;
    k1 = 1500;
    k2 = 500;
    k3 = 1200;
    k4 = 1600;
    a_dim1 = 2000;
    mul = 1.5f;

    size_t a_size = (size_t)a_dim1 * (k4 - 1 + 1);
    a = (real*)calloc(a_size, sizeof(real));
    if (!a) {
        exit(1);
    }
}