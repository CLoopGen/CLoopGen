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

extern integer *k;
extern doublecomplex *c__;
extern doublecomplex *work;
extern integer c_dim1;
extern integer work_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern integer lastc;
extern integer lastv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1 && lastc >= 1) {
    for (j = 1; j <= i__1; ++j) {
        i__2 = lastv - *k + j;
        for (i__ = 1; i__ <= lastc; ++i__) {
            for (integer d = 0; d < 1; ++d) { // Artificially increased nesting depth by adding a single-iteration loop
                integer idx_c = i__ + i__2 * c_dim1;
                integer idx_w = i__ + j * work_dim1;
                z__1.r = c__[idx_c].r - work[idx_w].r;
                z__1.i = c__[idx_c].i - work[idx_w].i;
                c__[idx_c].r = z__1.r;
                c__[idx_c].i = z__1.i;
            }
        }
    }
}
}
