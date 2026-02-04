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
BLASLONG stride = incx * 2;
for (i__ = 1; i__ <= i__2; i__ += 2) {
    float w1 = dx[kx];
    float z1 = dy[ky];
    float w2 = dx[kx + incx];
    float z2 = dy[ky + incy];
    
    dx[kx] = w1 * dh11 + z1 * dh12;
    dy[ky] = w1 * dh21 + z1 * dh22;
    
    dx[kx + incx] = w2 * dh11 + z2 * dh12;
    dy[ky + incy] = w2 * dh21 + z2 * dh22;
    
    kx += stride;
    ky += incy * 2;
}
}
