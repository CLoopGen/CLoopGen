#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *buf;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 124 && buf != NULL; i++) {
        float val = buf[i];
        if (val <= max) continue;
        max = val;
    }
}
