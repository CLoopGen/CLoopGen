#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern double *y;
extern int i;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len; i++) {
        tmp = x[i-1];        // Introduce loop-carried RAW dependency
        x[i] = y[i] + tmp;   // WAW: x[i] written after potential prior iteration write to same location
        y[i-1] = tmp;        // WAR: Write to y[i-1] after previous read in next iteration's tmp = x[i]
    }
    if (len > 0) {
        y[len-1] = tmp;      // Fix last element update to maintain some semantic similarity
    }
}
