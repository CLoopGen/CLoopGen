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
    logical skip_alpha = (*alpha == 1.F);
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real *b_ptr = &b[i__ + j * b_dim1];
        if (!skip_alpha) {
            *b_ptr = *alpha * (*b_ptr);
        }
        temp = *b_ptr;
        for (k = 1; k < j; ++k) {
            if (a[k + j * a_dim1] != 0.F) {
                temp -= a[k + j * a_dim1] * b[i__ + k * b_dim1];
            }
        }
        *b_ptr = temp;
        if (nounit && a[j + j * a_dim1] != 0.F) {
            *b_ptr /= a[j + j * a_dim1];
        }
    }
}
}
