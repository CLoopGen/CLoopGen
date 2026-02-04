#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect addressing via pointer arithmetic to simulate stride pattern
    real *x_ptr = x + *n;
    real *a_col_base = a + *n * a_dim1;
    integer stride = a_dim1;
    temp = 0.0f;

    for (j = *n; j >= 1; --j) {
        temp = *(x_ptr); // current x[j]
        if (nounit) {
            temp *= *(a_col_base + j); // a[j + j*a_dim1] accessed via base + offset
        }
        real sum = 0.0f;
        real *a_ptr = a_col_base - stride; // point to column j of a, row j-1
        real *x_sub = x_ptr - 1;           // &x[j-1]
        for (i__ = j - 1; i__ >= 1; --i__) {
            sum += (*a_ptr) * (*x_sub);
            a_ptr -= stride; // strided backward access in column j
            --x_sub;
        }
        *(x_ptr--) = temp + sum;
        a_col_base -= stride; // move to previous column base
    }
}
