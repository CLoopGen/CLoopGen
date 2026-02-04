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

typedef int logical;

extern integer *m;
extern doublecomplex *alpha;
extern doublecomplex *a;
extern doublecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern integer i__6;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern integer k;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (k = 1; k <= i__2; ++k) {
        i__3 = k + j * b_dim1;
        if (b[i__3].r != 0. || b[i__3].i != 0.) {
            // Introduce temporary accumulation with delayed write to reduce WAW and WAR hazards
            doublecomplex local_temp;
            i__3 = k + j * b_dim1;
            z__1.r = alpha->r * b[i__3].r - alpha->i * b[i__3].i;
            z__1.i = alpha->r * b[i__3].i + alpha->i * b[i__3].r;
            local_temp.r = z__1.r;
            local_temp.i = z__1.i;

            // Modify loop-carried dependency: reverse inner loop to change access pattern
            i__3 = k - 1;
            for (i__ = i__3; i__ >= 1; --i__) {  // Reversed loop direction introduces different RAW/WAR order
                i__4 = i__ + j * b_dim1;
                i__6 = i__ + k * a_dim1;
                z__2.r = local_temp.r * a[i__6].r - local_temp.i * a[i__6].i;
                z__2.i = local_temp.r * a[i__6].i + local_temp.i * a[i__6].r;
                z__1.r = b[i__4].r + z__2.r;
                z__1.i = b[i__4].i + z__2.i;
                b[i__4].r = z__1.r;
                b[i__4].i = z__1.i;
            }

            // Deferral of temp update until after loop removes partial dependency
            if (nounit) {
                i__3 = k + k * a_dim1;
                z__1.r = local_temp.r * a[i__3].r - local_temp.i * a[i__3].i;
                z__1.i = local_temp.r * a[i__3].i + local_temp.i * a[i__3].r;
                local_temp.r = z__1.r;
                local_temp.i = z__1.i;
            }
            i__3 = k + j * b_dim1;
            b[i__3].r = local_temp.r;
            b[i__3].i = local_temp.i;
        }
    }
}
}
