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
extern float dh22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_w, temp_z;
    BLASLONG j = kx, l = ky;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp_w = dx[j];
        temp_z = dy[l];
        dx[j] = temp_w * dh11 + temp_z;
        dy[l] = -temp_w + dh22 * temp_z;
        j += incx;
        l += incy;
    }
}
