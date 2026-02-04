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
float prev_w = 0.0f, prev_z = 0.0f;
for (i__ = 1; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) {
    w = dx[i__] + prev_w;
    z__ = dy[i__] + prev_z;
    dx[i__] = w * dh11 + z__;
    dy[i__] = -w + dh22 * z__;
    prev_w = w * 0.1f;
    prev_z = z__ * 0.1f;
}
}
