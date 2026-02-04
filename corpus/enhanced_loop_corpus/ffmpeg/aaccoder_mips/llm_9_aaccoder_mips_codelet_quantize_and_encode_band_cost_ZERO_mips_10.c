#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size; i += 2) {
    out[i] = (float)((int)(0.F + 1) - 1);
    out[i + 1] = (float)((int)(0.F + 1) - 1);
}
}
