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
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real *b_local = (real*)malloc(sizeof(real) * (*m + 1) * (i__1 + 1));
if (b_local == NULL) return;
for (j = 1; j <= i__1; ++j) {
    for (i__ = 1; i__ <= *m; ++i__) {
        b_local[i__ + j * b_dim1] = b[i__ + j * b_dim1];
    }
}
for (j = 1; j <= i__1; ++j) {
    for (i__ = *m; i__ >= 1; --i__) {
        temp = b_local[i__ + j * b_dim1];
        if (nounit) {
            temp *= a[i__ + i__ * a_dim1];
        }
        i__2 = i__ - 1;
        for (k = 1; k <= i__2; ++k) {
            temp += a[k + i__ * a_dim1] * b_local[k + j * b_dim1];
        }
        b[i__ + j * b_dim1] = *alpha * temp;
    }
}
free(b_local);
}
