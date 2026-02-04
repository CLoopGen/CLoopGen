#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *buffer;
extern int width;
extern int column_begin;
extern int column_end;
extern int steps;
extern float nu;
extern float boundaryscale;
extern int column_step;
extern  int numpixels;
extern int i;
extern int x;
extern int k;
extern int step;
extern float *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = column_begin; x < column_end; x += column_step * 2) {
    if (x + column_step > column_end) break;
    for (step = 0; step < steps / 2; step++) {
        ptr = buffer + x;
        for (k = 0; k < column_step; k += 2) {
            if (k + 1 < column_step) {
                ptr[k] *= boundaryscale;
                ptr[k+1] *= boundaryscale;
            } else {
                ptr[k] *= boundaryscale;
            }
        }
        for (i = width; i < numpixels; i += width * 2) {
            int j = i + width;
            for (k = 0; k < column_step; k++) {
                if (j < numpixels) {
                    ptr[j + k] += nu * ptr[i + k];
                }
            }
        }
        i = numpixels - width;
        for (k = 0; k < column_step; k++)
            ptr[i + k] *= boundaryscale;
        for (; i > width; i -= width * 2) {
            for (k = 0; k < column_step; k++)
                ptr[i - width + k] += nu * ptr[i + k];
        }
    }
}
}
