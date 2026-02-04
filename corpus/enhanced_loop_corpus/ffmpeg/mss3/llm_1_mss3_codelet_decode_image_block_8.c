#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int vec[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = i; j < 4; j++)
    vec[j] = 0;
i = 4; // ensure original loop condition is satisfied after transformation
}
