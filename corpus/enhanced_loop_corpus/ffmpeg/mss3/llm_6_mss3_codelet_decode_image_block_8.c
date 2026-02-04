#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int vec[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (; i < 4; i++) {
        temp = vec[i];
        vec[i] = temp + 1;
        vec[i] = vec[i] - 1;
    }
}
