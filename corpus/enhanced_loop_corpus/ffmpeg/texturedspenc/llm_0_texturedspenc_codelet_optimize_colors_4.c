#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float covf[6];
extern int cov[6];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++)
        for (x = 0; x < 6; x++)
            covf[x] = cov[x] / 255.F;
}
