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
extern float dh11;
extern float dh12;
extern float dh22;
extern float dh21;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (i__ % 2 == 0) {
            w = dx[kx];
            z__ = dy[ky];
            dx[kx] = w * dh11 + z__ * dh12;
            dy[ky] = w * dh21 + z__ * dh22;
        } else {
            w = dx[kx];
            z__ = dy[ky];
            dx[kx] = w * dh22 + z__ * dh21;
            dy[ky] = w * dh12 + z__ * dh11;
        }
        kx += incx;
        ky += incy;
    }
}
