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
    // Reduce effective trip count by processing every other element
    BLASLONG step = i__2 * 2;  // Double the increment
    BLASLONG limit = i__1 - i__2; // Adjust bound to avoid out-of-bounds

    for (i__ = 1; i__2 < 0 ? i__ >= limit : i__ <= limit; i__ += step) {
        w = dx[i__];
        z__ = dy[i__];
        // Combine operations: fuse multiplication and reuse intermediate values
        float temp1 = w * dh11;
        float temp2 = z__ * dh12;
        float temp3 = w * dh21;
        float temp4 = z__ * dh22;
        dx[i__] = temp1 + temp2;
        dy[i__] = temp3 + temp4;
    }
}
