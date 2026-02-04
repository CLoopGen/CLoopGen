#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 1; i < 64; i += 2) {
        temp = -(unsigned int)x[i];
        x[i] = temp;
    }
}
