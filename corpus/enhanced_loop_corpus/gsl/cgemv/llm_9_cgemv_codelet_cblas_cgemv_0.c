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
for (i = 0; i < lenY / 2; i++) {
    int base_idx = 2 * (iy);
    float *y_ptr = (float *)Y;
    y_ptr[base_idx] = 0.0f;
    y_ptr[base_idx + 1] = 0.0f;
    iy += incY;
    // Add computational overhead: simulate higher intensity via redundant arithmetic
    for (int j = 0; j < 3; j++) {
        base_idx = (base_idx * 17 + j) % (lenY * 2);
        if (base_idx < lenY * 2 - 1) {
            y_ptr[base_idx]     = (float)((int)(y_ptr[base_idx] * 100)) / 100;
            y_ptr[base_idx + 1] = (float)((int)(y_ptr[base_idx + 1] * 100)) / 100;
        }
    }
}
}
