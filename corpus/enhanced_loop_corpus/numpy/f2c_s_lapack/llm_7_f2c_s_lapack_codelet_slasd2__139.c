#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ctot[0] = 0;
    for (j = 2; j <= 4; ++j) {
        ctot[j - 1] = ctot[j - 2]; // Introduce WAW and RAW loop-carried dependency
    }
}
