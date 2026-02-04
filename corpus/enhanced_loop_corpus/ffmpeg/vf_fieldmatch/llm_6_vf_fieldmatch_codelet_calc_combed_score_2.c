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
    int temp_max = max_v;
    for (x = 0; x < arraysize; x++) {
        if (c_array[x] > temp_max)
            temp_max = c_array[x];
    }
    max_v = temp_max;
}
