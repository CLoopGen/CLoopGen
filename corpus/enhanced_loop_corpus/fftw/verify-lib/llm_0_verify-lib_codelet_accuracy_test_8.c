#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 1; ++j)
    for (i = 0; i < 6; ++i)
        t[i] = 0.;
}
