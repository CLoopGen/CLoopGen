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
    for (i__ = 1; i__ <= i__2; ++i__) {
        w = dx[kx];
        z__ = dy[ky];
        if (w * z__ >= 0.0f) {
            dx[kx] = w + z__ * dh12;
            dy[ky] = w * dh21 + z__;
        } else {
            dx[kx] = w;
            dy[ky] = z__;
        }
        kx += incx;
        ky += incy;
    }
}
