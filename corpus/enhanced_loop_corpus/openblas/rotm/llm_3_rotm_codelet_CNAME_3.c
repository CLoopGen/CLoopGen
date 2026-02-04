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
BLASLONG current_kx = kx;
BLASLONG current_ky = ky;
for (i__ = 1; i__ <= i__2; ++i__) {
    w = dx[current_kx];
    z__ = dy[current_ky];
    dx[current_kx] = w + z__ * dh12;
    dy[current_ky] = w * dh21 + z__;
    current_kx += incx;
    current_ky += incy;
}
}
