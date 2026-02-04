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
    float w_prev = 0.0f, z_prev = 0.0f;
    BLASLONG jx = kx;
    BLASLONG jy = ky;
    for (i__ = 1; i__ <= i__2; ++i__) {
        float current_w = dx[jx];
        float current_z = dy[jy];
        dx[jx] = current_w * dh11 + current_z * dh12 + w_prev * 0.1f;
        dy[jy] = current_w * dh21 + current_z * dh22 + z_prev * 0.1f;
        w_prev = current_w;
        z_prev = current_z;
        jx += incx;
        jy += incy;
    }
}
