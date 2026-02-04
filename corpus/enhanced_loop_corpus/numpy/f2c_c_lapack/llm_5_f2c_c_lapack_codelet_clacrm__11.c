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
extern singlecomplex *a;
extern real *rwork;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && *m > 0; ++j) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        real temp = a[i__3].r;
        if (temp != 0.0f) {
            rwork[(j - 1) * *m + i__] = temp * 2.0f;
        } else {
            rwork[(j - 1) * *m + i__] = 1.0f;
        }
    }
}
}
