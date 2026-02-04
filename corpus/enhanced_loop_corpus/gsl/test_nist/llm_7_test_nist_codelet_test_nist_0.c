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
double temp2, temp3, temp4;
for (i = 1; i < 1000; i += 2) {
    temp2 = 1.1000000000000001;
    temp3 = 1000000.1;
    temp4 = 10000000.1;
    numacc2[i + 1] = 1.3;
    numacc3[i + 1] = 1000000.3;
    numacc4[i + 1] = 10000000.300000001;
    numacc2[i] = temp2;
    numacc3[i] = temp3;
    numacc4[i] = temp4;
}
}
