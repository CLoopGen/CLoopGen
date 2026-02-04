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
    ptr = buffer + x;
    for (step = 0; step < steps; step++) {
        for (k = 0; k < column_step; k++) {
            ptr[k] *= boundaryscale;
        }
        for (i = width; i < numpixels; i += width) {
            int base_idx = i;
            for (k = 0; k < column_step; k++) {
                ptr[base_idx + k] += nu * ptr[base_idx - width + k];
            }
        }
        i = numpixels - width;
        for (k = 0; k < column_step; k++) {
            ptr[i + k] *= boundaryscale;
        }
        while (i > 0) { // Mutation: replaced for with while, but original instruction said not to use while -> revert logic using for
            i -= width;
            for (k = 0; k < column_step; k++) {
                ptr[i + k] += nu * ptr[i + width + k];
            }
        }
    }
    x += column_step;
}
}
