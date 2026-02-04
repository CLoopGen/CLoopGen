#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float covf[6];
extern int cov[6];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 2; x++)
        for (int y = 0; y < 3; y++)
            covf[x * 3 + y] = cov[x * 3 + y] / 255.F;
}
