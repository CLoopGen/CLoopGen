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
        // Change memory access to consecutive by unrolling and reordering k-loop
        for (k = 0; k < column_step; k += 4) {
            // Process 4 elements at a time assuming column_step is multiple of 4
            if (k + 0 < column_step) ptr[k + 0] *= boundaryscale;
            if (k + 1 < column_step) ptr[k + 1] *= boundaryscale;
            if (k + 2 < column_step) ptr[k + 2] *= boundaryscale;
            if (k + 3 < column_step) ptr[k + 3] *= boundaryscale;
        }
        for (i = width; i < numpixels; i += width) {
            for (k = 0; k < column_step; k += 4) {
                if (k + 0 < column_step) ptr[i + k + 0] += nu * ptr[i - width + k + 0];
                if (k + 1 < column_step) ptr[i + k + 1] += nu * ptr[i - width + k + 1];
                if (k + 2 < column_step) ptr[i + k + 2] += nu * ptr[i - width + k + 2];
                if (k + 3 < column_step) ptr[i + k + 3] += nu * ptr[i - width + k + 3];
            }
        }
        i = numpixels - width;
        for (k = 0; k < column_step; k += 4) {
            if (k + 0 < column_step) ptr[i + k + 0] *= boundaryscale;
            if (k + 1 < column_step) ptr[i + k + 1] *= boundaryscale;
            if (k + 2 < column_step) ptr[i + k + 2] *= boundaryscale;
            if (k + 3 < column_step) ptr[i + k + 3] *= boundaryscale;
        }
        for (; i > 0; i -= width) {
            for (k = 0; k < column_step; k += 4) {
                if (k + 0 < column_step) ptr[i - width + k + 0] += nu * ptr[i + k + 0];
                if (k + 1 < column_step) ptr[i - width + k + 1] += nu * ptr[i + k + 1];
                if (k + 2 < column_step) ptr[i - width + k + 2] += nu * ptr[i + k + 2];
                if (k + 3 < column_step) ptr[i - width + k + 3] += nu * ptr[i + k + 3];
            }
        }
    }
    x += column_step;
}
}
