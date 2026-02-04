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
extern float dh22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) {
    float temp_w = dx[i__];
    float temp_z = dy[i__];
    float new_dx = temp_w * dh11 + temp_z;
    float new_dy = -temp_w + dh22 * temp_z;
    dx[i__] = new_dx;
    dy[i__] = new_dy;
}
}
