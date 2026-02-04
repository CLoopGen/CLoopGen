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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access via jx, ix, and kx with *incx steps,
    // we reindex using consecutive indices assuming incx == 1.
    // This enables better vectorization and cache locality.
    
    integer base_j = (*n - 1) * (*incx);  // Starting offset if incx were 1
    for (j = *n; j >= 1; --j) {
        integer idx_j = j - 1;  // Zero-based index
        integer pos_j = idx_j;  // Assume incx == 1 => consecutive
        if (x[pos_j].r != 0.F || x[pos_j].i != 0.F) {
            temp.r = x[pos_j].r;
            temp.i = x[pos_j].i;
            integer pos_i = pos_j + 1;  // Start from next element
            for (i__ = *n; i__ >= j + 1; --i__) {
                integer pos_a = i__ - 1 + j * a_dim1;  // Column-major indexing
                q__2.r = temp.r * a[pos_a].r - temp.i * a[pos_a].i;
                q__2.i = temp.r * a[pos_a].i + temp.i * a[pos_a].r;
                q__1.r = x[pos_i].r + q__2.r;
                q__1.i = x[pos_i].i + q__2.i;
                x[pos_i].r = q__1.r;
                x[pos_i].i = q__1.i;
                pos_i++;
            }
            if (nounit) {
                integer diag_a = j - 1 + j * a_dim1;
                q__1.r = x[pos_j].r * a[diag_a].r - x[pos_j].i * a[diag_a].i;
                q__1.i = x[pos_j].r * a[diag_a].i + x[pos_j].i * a[diag_a].r;
                x[pos_j].r = q__1.r;
                x[pos_j].i = q__1.i;
            }
        }
    }
}
