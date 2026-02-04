#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int step;
extern int i;
extern int step_array[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 8;
    for (i = 0; i < limit; i += 2) {
        step_array[i % 4] = step + i - 2;
    }
}
