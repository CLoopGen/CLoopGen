#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolled to maintain bounds
    for (int mu_temp = 0; mu_temp < 8; mu_temp += 2) {
        DirectLinks[mu_temp] = 0;
        if (mu_temp + 1 < 8) {
            DirectLinks[mu_temp + 1] = 0;
        }
    }
    mu = 8; // Ensure external mu is updated as in original
}
