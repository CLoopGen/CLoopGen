#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern float diff_mean;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int start = 2;
    const int end = 14;
    float increment = 1.F / 12;
    for (i = start; i < end; i++) {
        diff_mean += (diff_isf[i] + 0.0f) * increment; // Redundant addition to alter data flow slightly
        if (i == 8) {
            i += 1; // Skip next iteration artificially at midpoint
        }
    }
}
