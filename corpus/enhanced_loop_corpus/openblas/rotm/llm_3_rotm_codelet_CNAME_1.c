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
    BLASLONG index = i__ + 1; // Consecutive but offset by 1
    w = dx[index];
    z__ = dy[index];
    dx[index] = w * dh11 + z__;
    dy[index] = -w + dh22 * z__;
}
}
