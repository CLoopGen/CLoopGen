#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int m = 0; m < 30; m += 2)
    temp[m % 15] -= d1 * 2.0;
}
