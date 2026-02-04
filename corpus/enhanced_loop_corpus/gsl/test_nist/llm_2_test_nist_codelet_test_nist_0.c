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
for (i = 0; i < 1000; i += 2) {
    size_t idx1 = i;
    size_t idx2 = i + 1;
    numacc2[idx1] = 1.1000000000000001;
    numacc2[idx2] = 1.3;
    numacc3[idx1] = 1000000.1;
    numacc3[idx2] = 1000000.3;
    numacc4[idx1] = 10000000.1;
    numacc4[idx2] = 10000000.300000001;
}
}
