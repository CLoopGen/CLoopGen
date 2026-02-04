#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int filter_limit;
extern int *bounding_values;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (x = 0; x < filter_limit; x++) {
        temp = -x;
        bounding_values[-x] = temp;
        bounding_values[x] = temp + 2*x; // introduces dependency on previous temp, but no loop-carried dep
    }
}
