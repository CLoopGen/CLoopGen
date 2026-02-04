#include <stdio.h>

typedef long BLASLONG;

extern float *dx;
extern BLASLONG incx;
extern float *dy;
extern BLASLONG incy;
extern BLASLONG i__2;
extern BLASLONG i__;
extern float w;
extern float z__;
extern BLASLONG kx;
extern BLASLONG ky;
extern float dh12;
extern float dh21;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG stride = 2;
for (i__ = 1; i__ <= i__2; i__ += stride) {
    BLASLONG kx1 = kx;
    BLASLONG ky1 = ky;
    BLASLONG kx2 = kx + incx;
    BLASLONG ky2 = ky + incy;

    float w1 = dx[kx1];
    float z1 = dy[ky1];
    float w2 = (i__ + 1 <= i__2) ? dx[kx2] : w1;
    float z2 = (i__ + 1 <= i__2) ? dy[ky2] : z1;

    dx[kx1] = w1 + z1 * dh12;
    dy[ky1] = w1 * dh21 + z1;

    if (i__ + 1 <= i__2) {
        dx[kx2] = w2 + z2 * dh12;
        dy[ky2] = w2 * dh21 + z2;
    }

    kx += incx * stride;
    ky += incy * stride;
}
}
