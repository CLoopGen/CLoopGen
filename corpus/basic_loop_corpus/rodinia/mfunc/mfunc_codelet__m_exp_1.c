#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int j2max;
extern double power2;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 1; k <= j2max; k++)
    power2 *= 2;

}
