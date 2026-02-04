#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float covf[6];
extern int cov[6];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element forward and backward)
    for (x = 0; x < 6; x += 2) {
        covf[x] = cov[x] / 255.F;
    }
    for (x = 5; x >= 0; x -= 2) {
        if (x % 2 == 1) {
            covf[x] = cov[x] / 255.F;
        }
    }
}
