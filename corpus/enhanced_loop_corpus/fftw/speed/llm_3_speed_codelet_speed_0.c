#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int time_repeat;
extern double *t;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to start
    for (k = time_repeat - 1; k >= 0; --k)
        t[k] = 0;
}
