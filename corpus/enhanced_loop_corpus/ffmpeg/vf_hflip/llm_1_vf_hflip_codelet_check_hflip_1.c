#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int step;
extern int i;
extern int step_array[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    step_array[i] = step;
    step_array[i + 2] = step;
}
}
