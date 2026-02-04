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
for (j = 1; j <= i__1; j += 2) {
    for (k = *m; k >= 1; --k) {
        integer j2 = j + 1;
        logical update1 = 0, update2 = 0;
        i__2 = k + j * b_dim1;
        i__3 = k + j2 * b_dim1;

        doublecomplex temp1, temp2;
        if (j <= i__1 && (b[i__2].r != 0. || b[i__2].i != 0.)) {
            update1 = 1;
            z__1.r = alpha->r * b[i__2].r - alpha->i * b[i__2].i;
            z__1.i = alpha->r * b[i__2].i + alpha->i * b[i__2].r;
            temp1.r = z__1.r;
            temp1.i = z__1.i;
        }
        if (j2 <= i__1 && (b[i__3].r != 0. || b[i__3].i != 0.)) {
            update2 = 1;
            z__1.r = alpha->r * b[i__3].r - alpha->i * b[i__3].i;
            z__1.i = alpha->r * b[i__3].i + alpha->i * b[i__3].r;
            temp2.r = z__1.r;
            temp2.i = z__1.i;
        }

        if (update1) {
            if (nounit) {
                i__3 = k + j * b_dim1;
                i__4 = k + k * a_dim1;
                z__1.r = temp1.r * a[i__4].r - temp1.i * a[i__4].i;
                z__1.i = temp1.r * a[i__4].i + temp1.i * a[i__4].r;
                b[i__3].r = z__1.r;
                b[i__3].i = z__1.i;
            } else {
                i__2 = k + j * b_dim1;
                b[i__2].r = temp1.r;
                b[i__2].i = temp1.i;
            }

            i__2 = *m;
            for (i__ = k + 1; i__ <= i__2; ++i__) {
                i__3 = i__ + j * b_dim1;
                i__5 = i__ + k * a_dim1;
                z__2.r = temp1.r * a[i__5].r - temp1.i * a[i__5].i;
                z__2.i = temp1.r * a[i__5].i + temp1.i * a[i__5].r;
                b[i__3].r += z__2.r;
                b[i__3].i += z__2.i;
            }
        }

        if (update2) {
            if (nounit) {
                i__3 = k + j2 * b_dim1;
                i__4 = k + k * a_dim1;
                z__1.r = temp2.r * a[i__4].r - temp2.i * a[i__4].i;
                z__1.i = temp2.r * a[i__4].i + temp2.i * a[i__4].r;
                b[i__3].r = z__1.r;
                b[i__3].i = z__1.i;
            } else {
                b[i__3].r = temp2.r;
                b[i__3].i = temp2.i;
            }

            i__2 = *m;
            for (i__ = k + 1; i__ <= i__2; ++i__) {
                i__3 = i__ + j2 * b_dim1;
                i__5 = i__ + k * a_dim1;
                z__2.r = temp2.r * a[i__5].r - temp2.i * a[i__5].i;
                z__2.i = temp2.r * a[i__5].i + temp2.i * a[i__5].r;
                b[i__3].r += z__2.r;
                b[i__3].i += z__2.i;
            }
        }
    }
}
}
