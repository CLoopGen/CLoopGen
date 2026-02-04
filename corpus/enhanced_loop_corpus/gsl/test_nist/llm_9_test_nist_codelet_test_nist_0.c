#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double numacc2[1001];
extern double numacc3[1001];
extern double numacc4[1001];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 500; i += 1) {
    double temp2_1 = 1.1000000000000001;
    double temp2_2 = 1.3;
    double temp3_1 = 1000000.1;
    double temp3_2 = 1000000.3;
    double temp4_1 = 10000000.1;
    double temp4_2 = 10000000.300000001;

    numacc2[2*i] = temp2_1;
    numacc2[2*i + 1] = temp2_2;
    numacc3[2*i] = temp3_1 + temp2_1;
    numacc3[2*i + 1] = temp3_2 + temp2_2;
    numacc4[2*i] = temp4_1 * (temp3_1 / 1000000.0);
    numacc4[2*i + 1] = temp4_2 * (temp3_2 / 1000000.0);

    // Additional computational load to increase intensity
    temp2_1 += 0.1;
    temp2_2 -= 0.1;
    numacc2[2*i] *= temp2_1;
    numacc2[2*i + 1] /= temp2_2;
}
}
