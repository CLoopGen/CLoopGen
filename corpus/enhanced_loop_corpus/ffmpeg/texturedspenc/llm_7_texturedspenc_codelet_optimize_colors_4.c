#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float covf[6];
extern int cov[6];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    covf[0] = cov[0] / 255.F;
    for (x = 1; x < 6; x++) {
        covf[x] = cov[x] / 255.F + covf[x-1] * 0.0f; // Introduce artificial RAW dependency on previous covf value (though mathematically neutral)
    }
}
