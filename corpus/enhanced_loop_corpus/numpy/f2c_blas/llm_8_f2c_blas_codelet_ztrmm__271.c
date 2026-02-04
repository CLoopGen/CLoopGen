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
    for (k = 1; k <= *m; ++k) { // Reversed loop direction introduces new loop-carried dependence pattern (WAW dependency order changed)
        i__2 = k + j * b_dim1;
        if (b[i__2].r == 0. && b[i__2].i == 0.) continue;
        z__1.r = alpha->r * b[i__2].r - alpha->i * b[i__2].i;
        z__1.i = alpha->r * b[i__2].i + alpha->i * b[i__2].r;
        temp.r = z__1.r; temp.i = z__1.i;
        b[i__2].r = temp.r; b[i__2].i = temp.i;
        if (nounit) {
            i__3 = k + j * b_dim1;
            i__4 = k + k * a_dim1;
            z__1.r = b[i__3].r * a[i__4].r - b[i__3].i * a[i__4].i;
            z__1.i = b[i__3].r * a[i__4].i + b[i__3].i * a[i__4].r;
            b[i__3].r = z__1.r; b[i__3].i = z__1.i;
        }
        for (i__ = *m; i__ >= k + 1; --i__) { // Reverse inner loop: changes data access order, modifies RAW/WAR dependencies
            i__3 = i__ + j * b_dim1;
            i__4 = i__ + j * b_dim1;
            i__5 = i__ + k * a_dim1;
            z__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i;
            z__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
            z__1.r = b[i__4].r - z__2.r; // Subtraction instead of addition: semantic variation but valid arithmetic
            z__1.i = b[i__4].i - z__2.i;
            b[i__3].r = z__1.r; b[i__3].i = z__1.i;
        }
    }
}
}
