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
    x = 0;
    for (; x < arraysize; ) {
        if (c_array[x] > max_v)
            max_v = c_array[x];
        x++;  // Loop structure flattened — effectively same logic but with manual increment, simulating altered nesting control
    }
}
