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
real *b_ptr = b;
real *a_col_base;
for (j = 0; j < i__1; ++j, b_ptr += b_dim1) {
    for (i__ = 0; i__ < *m; ++i__) {
        real *a_row = &a[i__ * a_dim1];
        temp = *alpha * b_ptr[i__];
        for (k = 0; k < i__; ++k) {
            temp -= a_row[k] * b_ptr[k];
        }
        if (nounit) {
            temp /= a_row[i__];
        }
        b_ptr[i__] = temp;
    }
}
}
