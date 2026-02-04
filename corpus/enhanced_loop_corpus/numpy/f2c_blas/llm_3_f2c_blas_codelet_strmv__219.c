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
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *index_map = (int*)malloc(sizeof(int) * (*n + 1));
for (int idx = 1; idx <= *n; ++idx) {
    index_map[idx] = idx;
}
for (j = 1; j <= i__1; ++j) {
    temp = x[jx];
    ix = jx;
    if (nounit) {
        temp *= a[index_map[j] + index_map[j] * a_dim1];
    }
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        ix += *incx;
        temp += a[index_map[i__] + index_map[j] * a_dim1] * x[ix];
    }
    x[jx] = temp;
    jx += *incx;
}
free(index_map);
}
