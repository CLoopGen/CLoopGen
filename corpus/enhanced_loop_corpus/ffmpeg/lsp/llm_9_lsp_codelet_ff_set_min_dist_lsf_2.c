#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lsf;
extern double min_spacing;
extern int size;
extern int i;
extern float prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_min = (float)min_spacing;
    for (i = 0; i < size; i++) {
        float candidate = prev + temp_min;
        if (lsf[i] < candidate) {
            lsf[i] = candidate;
        }
        prev = lsf[i];
    }
}
