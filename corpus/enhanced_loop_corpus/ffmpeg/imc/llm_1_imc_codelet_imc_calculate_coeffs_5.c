#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float workT2[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    for (; i < 32; ) {
        workT2[i] = 0.;
        i++;
    }
}
