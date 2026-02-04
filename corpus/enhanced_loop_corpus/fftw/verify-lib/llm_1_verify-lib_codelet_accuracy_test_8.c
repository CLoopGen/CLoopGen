#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; ++i)
    for (int k = 0; k < 3; ++k)
        t[i * 3 + k] = 0.;
}
