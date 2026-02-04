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
extern integer a_dim1;
extern integer ret_val;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    for (integer k = *m; k >= 1; --k) {
        for (i__ = k; i__ >= 1; --i__) {
            i__2 = i__ + j * a_dim1;
            if (a[i__2].r != 0.F || a[i__2].i != 0.F) {
                goto L10;
            }
        }
      L10:
        ret_val = ((ret_val) >= (i__) ? (ret_val) : (i__));
    }
}
}
