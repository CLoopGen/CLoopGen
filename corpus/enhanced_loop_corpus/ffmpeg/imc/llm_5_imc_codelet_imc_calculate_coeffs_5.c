#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float workT2[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        if (i >= 16)
            workT2[i] = 0.;
        else
            workT2[i] = 0.;
    }
}
