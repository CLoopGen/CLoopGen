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
if (i__2 < 0 ? 1 >= i__1 : 1 <= i__1) {
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
        w = dx[i__];
        z__ = dy[i__];
        dx[i__] = w * dh11 + z__ * dh12;
        dy[i__] = w * dh21 + z__ * dh22;
    }
} else {
    w = dx[1];
    z__ = dy[1];
    dx[1] = w * dh11 + z__ * dh12;
    dy[1] = w * dh21 + z__ * dh22;
}
}
