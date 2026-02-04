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

extern integer *m;
extern singlecomplex *alpha;
extern singlecomplex *x;
extern singlecomplex *y;
extern integer *incy;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern integer jy;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant using strided memory access through precomputed indices with indirect-like traversal
integer *index_map = (integer*)malloc(*m * sizeof(integer));
if (!index_map) return; // Fail gracefully if allocation fails
for (i__ = 0; i__ < *m; ++i__) {
    index_map[i__] = (*m - 1) - i__;  // Reverse index mapping to simulate non-consecutive, strided/permuted access
}

for (j = 1; j <= i__1; ++j) {
    i__2 = jy;
    if (y[i__2].r != 0.F || y[i__2].i != 0.F) {
        i__2 = jy;
        q__1.r = alpha->r * y[i__2].r - alpha->i * y[i__2].i;
        q__1.i = alpha->r * y[i__2].i + alpha->i * y[i__2].r;
        temp.r = q__1.r; temp.i = q__1.i;

        for (i__ = 0; i__ < *m; ++i__) {  // Zero-based indexing for map access
            integer actual_i = index_map[i__] + 1;  // Map to original 1-based logic
            i__3 = actual_i + j * a_dim1;
            i__4 = actual_i + j * a_dim1;
            i__5 = actual_i;
            q__2.r = x[i__5].r * temp.r - x[i__5].i * temp.i;
            q__2.i = x[i__5].r * temp.i + x[i__5].i * temp.r;
            q__1.r = a[i__4].r + q__2.r;
            q__1.i = a[i__4].i + q__2.i;
            a[i__3].r = q__1.r;
            a[i__3].i = q__1.i;
        }
    }
    jy += *incy;
}
free(index_map);
}
