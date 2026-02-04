#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern integer *k;
extern real *alpha;
extern real *a;
extern real *b;
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    for (l = 1; l <= *k; ++l) {
        for (i__ = 1; i__ <= *m; ++i__) {
            real product = a[l + i__ * a_dim1] * b[j + l * b_dim1];
            if (l == 1) {
                temp = 0.F;
            }
            temp += product;
            if (l == *k) {
                if (*beta == 0.F) {
                    c__[i__ + j * c_dim1] = *alpha * temp;
                } else {
                    c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[i__ + j * c_dim1];
                }
            }
        }
    }
}
}
