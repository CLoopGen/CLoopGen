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
        // Use strided access: traverse k with a non-unit stride to simulate cache-friendly or transformed layout
        int stride = (column_step + 3) / 4; // Example: divide into 4 virtual lanes
        for (int s = 0; s < stride; s++) {
            for (k = s; k < column_step; k += stride) {
                ptr[k] *= boundaryscale;
            }
        }
        for (i = width; i < numpixels; i += width) {
            for (int s = 0; s < stride; s++) {
                for (k = s; k < column_step; k += stride) {
                    ptr[i + k] += nu * ptr[i - width + k];
                }
            }
        }
        i = numpixels - width;
        for (int s = 0; s < stride; s++) {
            for (k = s; k < column_step; k += stride) {
                ptr[i + k] *= boundaryscale;
            }
        }
        for (; i > 0; i -= width) {
            for (int s = 0; s < stride; s++) {
                for (k = s; k < column_step; k += stride) {
                    ptr[i - width + k] += nu * ptr[i + k];
                }
            }
        }
    }
    x += column_step;
}
}
