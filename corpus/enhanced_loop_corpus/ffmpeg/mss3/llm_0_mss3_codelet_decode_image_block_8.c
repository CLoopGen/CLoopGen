#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int vec[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer_i;
for (outer_i = 0; outer_i < 1; outer_i++)
    for (; i < 4; i++)
        vec[i] = 0;
}
