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
if (i__1 < 0 ? i__ >= i__2 : i__ <= i__2) {
    do {
        w = dx[i__];
        z__ = dy[i__];
        dx[i__] = w * dh11 + z__;
        dy[i__] = -w + dh22 * z__;
        i__ += i__1;
    } while (i__1 < 0 ? i__ >= i__2 : i__ <= i__2);
}
}
