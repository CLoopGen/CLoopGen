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
for (x = column_begin; x < column_end;) {
    for (step = 0; step < steps; step++) {
        ptr = buffer + x;
        for (k = 0; k < column_step; k++) {
            ptr[k] *= boundaryscale;
        }
        for (i = width; i < numpixels - width; i += width) {
            for (k = 0; k < column_step; k++) {
                float temp = ptr[i - width + k];
                ptr[i + k] += nu * temp;
                ptr[i + k] *= 1.0f + 0.001f * temp; // Additional arithmetic to increase computational intensity
            }
        }
        i = numpixels - 2 * width;
        if (i >= 0) {
            for (k = 0; k < column_step; k++) {
                ptr[i + k] += nu * ptr[i - width + k];
            }
        }
        i = numpixels - width;
        for (k = 0; k < column_step; k++)
            ptr[i + k] *= boundaryscale;
        for (; i > width; i -= width) {
            for (k = 0; k < column_step; k++)
                ptr[i - width + k] += nu * ptr[i + k] * (1.0f + 0.001f * ptr[i + k]);
        }
    }
    x += column_step;
}
}
