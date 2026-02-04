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
for (i__ = 1; i__ <= i__2; i__ += 2) {
    BLASLONG kx1 = kx, kx2 = kx + incx;
    BLASLONG ky1 = ky, ky2 = ky + incy;
    
    if (i__ + 1 <= i__2) {
        w = dx[kx1];
        z__ = dy[ky1];
        dx[kx1] = w * dh11 + z__;
        dy[ky1] = -w + dh22 * z__;
        
        w = dx[kx2];
        z__ = dy[ky2];
        dx[kx2] = w * dh11 + z__;
        dy[ky2] = -w + dh22 * z__;
        
        kx += 2 * incx;
        ky += 2 * incy;
    } else {
        w = dx[kx1];
        z__ = dy[ky1];
        dx[kx1] = w * dh11 + z__;
        dy[ky1] = -w + dh22 * z__;
        break;
    }
}
}
