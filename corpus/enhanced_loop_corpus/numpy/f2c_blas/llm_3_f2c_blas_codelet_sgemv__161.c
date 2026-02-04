#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *x;
extern integer *incx;
extern real *y;
extern integer *incy;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer iy;
extern integer jx;
extern integer ky;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Use pointers with fixed stride to simulate strided access and improve clarity
    real alpha_val = *alpha;
    integer incx_val = *incx;
    integer incy_val = *incy;
    integer m_val = *m;

    const real* x_ptr = x;
    real* y_ptr = y;
    const real* a_ptr = a;

    for (j = 0; j < i__1; ++j) {
        integer j_index = j * incx_val;
        if (x_ptr[j_index] != 0.F) {
            temp = alpha_val * x_ptr[j_index];
            real* y_iter = y_ptr + ky;
            const real* a_iter = a_ptr + j * a_dim1;
            for (i__ = 0; i__ < m_val; ++i__) {
                y_iter[i__ * incy_val] += temp * a_iter[i__];
            }
        }
    }
}
