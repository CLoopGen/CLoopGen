#include <stdio.h>

typedef long BLASLONG;

extern float *dx;
extern float *dy;
extern BLASLONG i__1;
extern BLASLONG i__2;
extern BLASLONG i__;
extern float w;
extern float z__;
extern float dh12;
extern float dh21;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
    w = dx[i__];
    z__ = dy[i__];
    dx[i__] = w + z__ * dh12;
    dy[i__] = w * dh21 + z__;
    // Unrolled to process two iterations per loop cycle, increasing arithmetic operations and computational intensity
    if ((i__ + i__2) <= i__1 || (i__2 < 0 && (i__ + i__2) >= i__1)) {
        BLASLONG next_i = i__ + i__2;
        float w2 = dx[next_i];
        float z2 = dy[next_i];
        dx[next_i] = w2 + z2 * dh12;
        dy[next_i] = w2 * dh21 + z2;
        i__ += i__2; // Compensate for loop increment
    }
}
}
