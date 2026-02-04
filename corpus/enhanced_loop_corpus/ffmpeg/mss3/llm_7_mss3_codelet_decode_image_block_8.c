#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int vec[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_vec[4];
    for (; i < 4; i++)
        local_vec[i] = 0;
    for (i = 0; i < 4; i++)
        vec[i] = local_vec[i];
}
