#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int step;
extern int i;
extern int step_array[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        if (i > 0)
            step_array[i] = step_array[i-1] + step;
        else
            step_array[i] = step;
    }
}
