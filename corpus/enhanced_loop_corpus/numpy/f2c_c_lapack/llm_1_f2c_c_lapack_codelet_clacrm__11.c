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
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (integer block = 1; block <= i__2; block += 16) {
        for (i__ = block; i__ <= ((block + 15 < i__2) ? block + 15 : i__2); ++i__) {
            i__3 = i__ + j * a_dim1;
            rwork[(j - 1) * *m + i__] = a[i__3].r;
        }
    }
}
}
