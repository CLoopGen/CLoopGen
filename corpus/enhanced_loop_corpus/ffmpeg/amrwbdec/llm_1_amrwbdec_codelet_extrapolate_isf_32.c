#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 20 - 1; i += 2) {
        isf[i] *= 0.80000000000000004;
        if (i + 1 < 20 - 1)
            isf[i + 1] *= 0.80000000000000004;
    }
}
