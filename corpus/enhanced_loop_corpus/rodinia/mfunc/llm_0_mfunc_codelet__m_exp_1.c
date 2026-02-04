#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int j2max;
extern double power2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k, i;
for (k = 1; k <= j2max; k++)
    for (i = 0; i < 1; i++)
        power2 *= 2;
}
