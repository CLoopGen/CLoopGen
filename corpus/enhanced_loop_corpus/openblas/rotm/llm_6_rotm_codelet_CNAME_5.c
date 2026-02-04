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
    float temp_w, temp_z;
    BLASLONG jx = kx;
    BLASLONG jy = ky;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp_w = dx[jx];
        temp_z = dy[jy];
        dx[jx] = temp_w * dh11 + temp_z * dh12;
        dy[jy] = temp_w * dh21 + temp_z * dh22;
        jx += incx;
        jy += incy;
    }
}
