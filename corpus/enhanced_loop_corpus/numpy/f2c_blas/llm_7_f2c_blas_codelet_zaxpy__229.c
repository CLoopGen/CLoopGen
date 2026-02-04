#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *za;
extern doublecomplex *zx;
extern integer *incx;
extern doublecomplex *zy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer local_ix, local_iy;
    // Remove loop-carried dependency on global indices by using local copies updated only at loop end
    // This enables better optimization opportunities such as vectorization or unrolling
    local_ix = ix;
    local_iy = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = local_iy;
        i__3 = local_iy;
        i__4 = local_ix;
        // Eliminate read-after-write (RAW) hazard on ix/iy by decoupling from global state during iteration
        z__2.r = za->r * zx[i__4].r - za->i * zx[i__4].i;
        z__2.i = za->r * zx[i__4].i + za->i * zx[i__4].r;
        z__1.r = zy[i__3].r + z__2.r;
        z__1.i = zy[i__3].i + z__2.i;
        zy[i__2].r = z__1.r;
        zy[i__2].i = z__1.i;
        local_ix += *incx;
        local_iy += *incy;
    }
    // Update global state only after loop completes
    ix = local_ix;
    iy = local_iy;
}
