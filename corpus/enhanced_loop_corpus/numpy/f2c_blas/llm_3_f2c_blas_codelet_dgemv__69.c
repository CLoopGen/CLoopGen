#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *x;
extern integer *incx;
extern doublereal *y;
extern integer *incy;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer iy;
extern integer jx;
extern integer ky;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer* index_map_x = (integer*)malloc(i__1 * sizeof(integer));
for (j = 1; j <= i__1; ++j) {
    index_map_x[j-1] = 1 + (j - 1) * (*incx);
}
for (j = 1; j <= i__1; ++j) {
    integer mapped_jx = index_map_x[j-1];
    if (x[mapped_jx] != 0.) {
        temp = *alpha * x[mapped_jx];
        iy = ky;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            y[iy] += temp * a[i__ + j * a_dim1];
            iy += *incy;
        }
    }
}
free(index_map_x);
}
