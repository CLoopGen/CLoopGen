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
for (i__ = 0; i__ < i__2; ++i__) {
    BLASLONG idx_x = kx + i__ * incx;
    BLASLONG idx_y = ky + i__ * incy;
    w = dx[idx_x];
    z__ = dy[idx_y];
    dx[idx_x] = w + z__ * dh12;
    dy[idx_y] = w * dh21 + z__;
}
}
