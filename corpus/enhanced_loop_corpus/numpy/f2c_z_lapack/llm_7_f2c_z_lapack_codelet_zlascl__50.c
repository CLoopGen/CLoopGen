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
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__3 = j + 1;
    i__2 = ((i__3) <= (*m) ? (i__3) : (*m));
    doublecomplex temp_sum; // Introduce local accumulation to modify data flow
    temp_sum.r = 0.0;
    temp_sum.i = 0.0;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__4 = i__ + j * a_dim1;
        // Accumulate scaled values in a local variable (introducing intra-loop dependency)
        z__1.r = mul * a[i__4].r;
        z__1.i = mul * a[i__4].i;
        temp_sum.r += z__1.r;
        temp_sum.i += z__1.i;
    }
    // Store accumulated result to a single element after inner loop (converts WAW into reduction + single write)
    i__3 = 1 + j * a_dim1;
    a[i__3].r = temp_sum.r;
    a[i__3].i = temp_sum.i;
}
}
