#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ilow;
extern size_t ihigh;
extern double mean;
extern double k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_k = k;
    double accumulated_delta = 0.0;
    double dummy = 0.0;
    for (i = ilow; i <= ihigh; ++i) {
        double delta;
        delta = (i & 1) ? 1.5 : -0.5;
        accumulated_delta += delta;
        local_k += 1.0;
        dummy += delta * local_k; // Introduce WAR: `delta` written before used in next iteration via dummy
    }
    k = local_k;
    mean += accumulated_delta / k;
}
