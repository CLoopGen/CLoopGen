#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (k = 1; k <= i__2; ++k) {
        real bjv = b[k + j * b_dim1];
        if (bjv == 0.F) continue;
        temp = *alpha * bjv;
        i__3 = k;
        for (i__ = 1; i__ < i__3; ++i__) {
            b[i__ + j * b_dim1] += temp * a[i__ + k * a_dim1];
        }
        b[k + j * b_dim1] = nounit ? temp * a[k + k * a_dim1] : temp;
    }
}
}
