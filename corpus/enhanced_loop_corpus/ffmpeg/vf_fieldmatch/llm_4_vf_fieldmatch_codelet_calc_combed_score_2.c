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
    for (x = 0; x < arraysize; x++) {
        int val = c_array[x];
        if (val <= max_v) continue;
        max_v = val;
    }
}
