#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *right;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with stride-based sampling (every 2nd element), decreasing computational load
    for (i = 0; i < ni; i += 2) {
        right[i] = p[i];
    }
}
