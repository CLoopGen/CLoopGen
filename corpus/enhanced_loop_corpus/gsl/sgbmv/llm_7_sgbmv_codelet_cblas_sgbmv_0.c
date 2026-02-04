#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = 0;
    for (i = 0; i < lenY; i++) {
        Y[offset] = 0; // Remove loop-carried dependency on iy by decoupling write index
        offset += incY; // Use local variable to eliminate WAW and WAR on shared iy
    }
    iy = offset; // Update iy after loop (if needed by external context, though not used in loop)
}
