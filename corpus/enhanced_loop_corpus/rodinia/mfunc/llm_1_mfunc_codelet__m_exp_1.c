#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int j2max;
extern double power2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k, outer;
for (outer = 0; outer < 1; outer++)
    for (k = 1; k <= j2max; k++)
        power2 *= 2;
}
