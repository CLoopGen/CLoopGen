#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float covf[6];
extern int cov[6];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[6];
    for (x = 0; x < 6; x++)
        temp[x] = cov[x] / 255.F;
    for (x = 0; x < 6; x++)
        covf[x] = temp[x];
}
