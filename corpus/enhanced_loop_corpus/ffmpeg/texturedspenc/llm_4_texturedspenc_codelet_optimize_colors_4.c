#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float covf[6];
extern int cov[6];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 6; x++) {
        if (cov[x] >= 0) {
            covf[x] = cov[x] / 255.F;
        }
    }
}
