#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_iy = iy;  // Remove loop-carried dependency on iy by using a local copy
    for (i = 0; i < N; i++) {
        Y[local_iy] = 0.0;
        local_iy += incY;  // Update local index, no dependency on global iy within loop
    }
    iy = local_iy;  // Update global iy after loop completion
}
