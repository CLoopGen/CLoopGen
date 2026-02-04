#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int vec[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {3, 2, 1, 0};
    for (; i < 4; i++)
        vec[indices[i]] = 0;
}
