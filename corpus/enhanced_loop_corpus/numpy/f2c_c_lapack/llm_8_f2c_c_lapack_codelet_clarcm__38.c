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
extern singlecomplex *c__;
extern real *rwork;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern real r__1;
extern singlecomplex q__1;
extern integer i__;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    real temp_real = 0.0f;
    singlecomplex temp_comp;
    // Introduce loop-carried dependency via accumulation in temp
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        i__4 = i__ + j * c_dim1;
        r__1 = c__[i__4].r;
        i__5 = l + (j - 1) * *m + i__ - 1;
        // Accumulate a running value across iterations (introduced WAW and loop-carried dependency)
        temp_real += r__1; 
        q__1.r = temp_real; // Now each iteration depends on previous one
        q__1.i = rwork[i__5] + temp_real; // Introduce dependency on computed real part
        c__[i__3].r = q__1.r;
        c__[i__3].i = q__1.i;
    }
    // Final write outside inner loop using accumulated temp (alters data flow)
    i__3 = 1 + j * c_dim1;
    c__[i__3].r += temp_real * 0.1f; // Side effect mutation
}
}
