#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int logical;

extern integer *n;
extern singlecomplex *a;
extern singlecomplex *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern integer kx;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Indexed) Memory Access Pattern
    // Replace arithmetic-based strided access with explicit index arrays.
    // Simulate indirect addressing using precomputed index vectors for x and a.
    // This reflects scenarios where data layout is non-uniform or gathered.

    integer* restrict x_index = (integer*)alloca(*n * sizeof(integer));
    integer* restrict a_col_index = (integer*)alloca(*n * sizeof(integer));
    
    // Precompute indirect indices assuming arbitrary stride or permutation
    for (i__ = 0; i__ < *n; ++i__) {
        x_index[i__] = (i__ * *incx);  // Could be non-regular pattern
        a_col_index[i__] = i__ * a_dim1;
    }

    integer j_idx = *n - 1;
    for (j = *n; j >= 1; --j) {
        integer j_off = x_index[j_idx];
        if (x[j_off].r != 0.F || x[j_off].i != 0.F) {
            temp.r = x[j_off].r;
            temp.i = x[j_off].i;
            integer i_idx = j_idx + 1;  // Start from next in reverse order
            for (i__ = *n; i__ >= j + 1; --i__) {
                integer i_off = x_index[i_idx];
                integer a_off = i__ - 1 + a_col_index[j - 1];  // j-1 due to zero-based
                q__2.r = temp.r * a[a_off].r - temp.i * a[a_off].i;
                q__2.i = temp.r * a[a_off].i + temp.i * a[a_off].r;
                q__1.r = x[i_off].r + q__2.r;
                q__1.i = x[i_off].i + q__2.i;
                x[i_off].r = q__1.r;
                x[i_off].i = q__1.i;
                i_idx++;
            }
            if (nounit) {
                integer diag_a = j - 1 + a_col_index[j - 1];
                q__1.r = x[j_off].r * a[diag_a].r - x[j_off].i * a[diag_a].i;
                q__1.i = x[j_off].r * a[diag_a].i + x[j_off].i * a[diag_a].r;
                x[j_off].r = q__1.r;
                x[j_off].i = q__1.i;
            }
        }
        j_idx--;
    }
}
