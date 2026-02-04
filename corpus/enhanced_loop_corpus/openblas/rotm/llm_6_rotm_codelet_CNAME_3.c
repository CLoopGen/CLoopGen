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
    float temp_w, temp_z;
    BLASLONG local_kx = kx;
    BLASLONG local_ky = ky;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp_w = dx[local_kx];
        temp_z = dy[local_ky];
        dx[local_kx] = temp_w + temp_z * dh12;
        dy[local_ky] = temp_w * dh21 + temp_z;
        local_kx += incx;
        local_ky += incy;
    }
}
