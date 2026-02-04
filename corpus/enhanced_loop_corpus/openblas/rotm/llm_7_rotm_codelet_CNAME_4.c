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
    float w_prev = 0.0f, z_prev = 0.0f;
    BLASLONG j = kx, l = ky;
    int first_iteration = 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        float current_w = dx[j];
        float current_z = dy[l];
        
        if (!first_iteration) {
            dx[j] = w_prev * dh11 + z_prev;
            dy[l] = -w_prev + dh22 * z_prev;
        } else {
            first_iteration = 0;
        }

        w_prev = current_w;
        z_prev = current_z;

        j += incx;
        l += incy;
    }
    // Final update using last saved values
    if (i__2 > 0) {
        BLASLONG final_kx = kx + (i__2 - 1) * incx;
        BLASLONG final_ky = ky + (i__2 - 1) * incy;
        dx[final_kx] = w_prev * dh11 + z_prev;
        dy[final_ky] = -w_prev + dh22 * z_prev;
    }
}
