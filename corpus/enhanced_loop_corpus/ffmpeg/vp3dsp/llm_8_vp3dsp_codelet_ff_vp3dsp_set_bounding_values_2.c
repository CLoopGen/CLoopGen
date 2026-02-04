#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int filter_limit;
extern int *bounding_values;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < filter_limit; x += 2) {
        if (x + 1 < filter_limit) {
            bounding_values[-x] = -x;
            bounding_values[x] = x;
            bounding_values[-(x+1)] = -(x+1);
            bounding_values[(x+1)] = (x+1);
        } else {
            bounding_values[-x] = -x;
            bounding_values[x] = x;
        }
    }
}
