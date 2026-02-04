#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int filter_limit;
extern int *bounding_values;
extern int x;
extern int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = value = filter_limit; x < 128 && value; x++, value--) {
    bounding_values[x] = value;
    if (x != 0) {
        bounding_values[-x] = -value;
    }
}
}
