#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int maxsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[128];
    for (i = 0; i < sizeof(maxsf) / sizeof(maxsf[0]); ++i) {
        temp[i] = 255;
        maxsf[i] = temp[i];
    }
}
