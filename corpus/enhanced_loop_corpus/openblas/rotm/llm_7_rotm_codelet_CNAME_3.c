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
    float prev_w = 0.0f, prev_z = 0.0f;
    for (i__ = 1; i__ <= i__2; ++i__) {
        float w = dx[kx];
        float z__ = dy[ky];
        dx[kx] = (i__ == 1) ? (w + z__ * dh12) : (w + prev_z * dh12);
        dy[ky] = (i__ == 1) ? (w * dh21 + z__) : (prev_w * dh21 + z__);
        prev_w = w;
        prev_z = z__;
        kx += incx;
        ky += incy;
    }
}
