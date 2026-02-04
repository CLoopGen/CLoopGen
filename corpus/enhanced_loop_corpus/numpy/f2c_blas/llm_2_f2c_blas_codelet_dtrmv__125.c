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
extern integer *incx;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base indices and using pointer arithmetic
    integer j_start = *n;
    integer j_end = 1;
    integer i_start, i_end;
    doublereal *a_col_base;
    doublereal *x_vec = x;
    integer ix_offset;

    for (j = j_start; j >= j_end; --j) {
        integer jx_idx = jx;
        temp = x_vec[jx_idx];
        ix = jx_idx;
        
        if (nounit) {
            temp *= a[j + j * a_dim1];
        }
        
        a_col_base = &a[j * a_dim1];  // Base pointer for column j of matrix a
        i_start = j - 1;
        i_end = 1;
        
        for (i__ = i_start; i__ >= i_end; --i__) {
            ix -= *incx;
            temp += a_col_base[i__] * x_vec[ix];
        }
        
        x_vec[jx_idx] = temp;
        jx -= *incx;
    }
}
