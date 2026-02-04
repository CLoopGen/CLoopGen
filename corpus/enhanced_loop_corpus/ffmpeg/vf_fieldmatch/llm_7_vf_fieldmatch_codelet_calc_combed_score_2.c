#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int max_v;
extern int *c_array;
extern  int arraysize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_max = c_array[0];
    for (x = 1; x < arraysize; x++) {
        local_max = (c_array[x] > local_max) ? c_array[x] : local_max;
    }
    if (local_max > max_v)
        max_v = local_max;
}
