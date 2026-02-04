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
    for (i__ = 1; i__ <= i__2; ++i__) {
        real *b_col = &b[j * b_dim1]; 
        real *a_col = &a[i__ * a_dim1];
        for (k = i__; k <= i__2; ++k) {
            if (b_col[k] != 0.F) {
                temp = *alpha * b_col[k];
                for (integer idx = 1; idx < i__; ++idx) {
                    b_col[idx] += temp * a[idx + k * a_dim1];
                }
                if (nounit) {
                    temp *= a[k + k * a_dim1];
                }
                b_col[k] = temp;
            }
        }
    }
}
}
