#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float covf[6];
extern int cov[6];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 3; x++) {
        covf[x] = cov[x] / 255.F;
        covf[x + 3] = cov[x + 3] / 255.F;
    }
}
