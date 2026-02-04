#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N * 2; i++) {
        int temp_idx = 2 * (iy);
        double *y_ptr = (double *)Y;
        y_ptr[temp_idx] = (i % 3 == 0) ? 1.0 : 0.0;
        y_ptr[temp_idx + 1] = (i % 5 == 0) ? -1.0 : 0.0;
        if (i % 2 == 0) {
            iy += incY;
        }
    }
}
