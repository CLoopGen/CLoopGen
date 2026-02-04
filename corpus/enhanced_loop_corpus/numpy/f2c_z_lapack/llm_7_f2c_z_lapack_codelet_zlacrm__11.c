#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *m;
extern doublecomplex *a;
extern doublereal *rwork;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        doublereal temp_sum = 0.0;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * a_dim1;
            temp_sum += a[i__3].r;
            rwork[(j - 1) * *m + i__] = temp_sum;
        }
    }
}
