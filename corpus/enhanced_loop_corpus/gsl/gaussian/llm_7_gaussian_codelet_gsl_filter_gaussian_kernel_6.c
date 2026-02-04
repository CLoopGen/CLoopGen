#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t order;
extern size_t i;
extern  double beta;
extern double q[11];
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= order; ++k) {
    double temp_q[12] = {0}; // Local buffer to eliminate WAW and WAR hazards
    for (i = 1; i <= k; ++i) {
        temp_q[i] = (i + 1.) * q[i + 1] + 2. * beta * q[i - 1];
    }
    // Update q only after all reads are complete to remove loop-carried WAW/RAW
    q[0] = q[1];
    for (i = 1; i <= k; ++i) {
        q[i] = temp_q[i];
    }
}
}
