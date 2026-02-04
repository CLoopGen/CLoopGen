#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int filter_limit;
extern int *bounding_values;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_val = 0;
    for (x = 0; x < filter_limit; x++) {
        int current = x + prev_val; // introduces loop-carried RAW dependency
        bounding_values[x] = current;
        bounding_values[-x] = -current;
        prev_val = current; // WAW: write after write pattern via prev_val carried across iterations
    }
}
