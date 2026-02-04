#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float *ceps_0;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < 22; i++)
    ceps_0[i] = features[i];

}
