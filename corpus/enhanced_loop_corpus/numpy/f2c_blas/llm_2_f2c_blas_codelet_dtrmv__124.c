#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *n;
extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Transform the original backward iteration into a forward iteration with pointer arithmetic
    // to access memory in a more cache-friendly, consecutive manner.
    doublereal *x_ptr = x + *n;
    doublereal *a_col_ptr = a + *n * a_dim1;
    for (j = *n; j >= 1; --j) {
        temp = *x_ptr;
        if (nounit) {
            temp *= *(a_col_ptr + j);
        }
        doublereal sum = 0.0;
        doublereal *a_temp = a_col_ptr;
        doublereal *x_temp = x + j - 1;
        for (i__ = j - 1; i__ >= 1; --i__) {
            sum += (*a_temp) * (*x_temp);
            --a_temp;
            --x_temp;
        }
        temp += sum;
        *x_ptr = temp;
        --x_ptr;
        --a_col_ptr;
    }
}
