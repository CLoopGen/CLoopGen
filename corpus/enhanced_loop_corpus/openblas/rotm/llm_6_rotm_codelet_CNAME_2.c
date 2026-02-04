#include <stdio.h>

typedef long BLASLONG;

extern float *dx;
extern float *dy;
extern BLASLONG i__1;
extern BLASLONG i__2;
extern BLASLONG i__;
extern float w;
extern float z__;
extern float dh11;
extern float dh12;
extern float dh22;
extern float dh21;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_dx, temp_dy;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
        w = dx[i__];
        z__ = dy[i__];
        temp_dx = w * dh11 + z__ * dh12;
        temp_dy = w * dh21 + z__ * dh22;
        dx[i__] = temp_dx;
        dy[i__] = temp_dy;
    }
}
