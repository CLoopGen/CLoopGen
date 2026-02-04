#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with indirect indexing using an index array (simulated)
    // Assume iy is now an array of starting indices, and incY controls stride across it
    // Here we simulate indirect access by treating iy as a base that increments per iteration
    volatile int current_iy = iy; // Prevent optimization assuming constant
    float *yPtr = (float *)Y;
    for (i = 0; i < lenY; i++) {
        int offset = 2 * current_iy;
        yPtr[offset] = 0.0f;
        yPtr[offset + 1] = 0.0f;
        current_iy += incY;
    }
}
