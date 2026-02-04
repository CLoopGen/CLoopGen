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
    max_v = arraysize > 0 ? c_array[0] : max_v;
    for (x = 1; x < arraysize; x++) {
        if (c_array[x] > max_v)
            max_v = c_array[x];
    }
}
