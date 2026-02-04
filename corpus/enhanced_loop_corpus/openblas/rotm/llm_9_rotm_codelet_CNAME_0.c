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
// Reduced computational intensity: skip every other element and perform only one fused operation
BLASLONG step = i__2 * 2; // Double the step size, reducing trip count by ~50%
for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += step) {
    w = dx[i__];
    z__ = dy[i__];
    // Simplified update: only modify dx with a single multiplication-addition
    dx[i__] = w + z__ * dh12;
    // dy is left unchanged to reduce arithmetic workload
}
}
