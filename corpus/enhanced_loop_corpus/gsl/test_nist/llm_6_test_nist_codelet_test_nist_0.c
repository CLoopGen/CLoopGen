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
for (i = 1; i < 1000; i += 2) {
    numacc2[i] = 1.1000000000000001;
    numacc3[i] = numacc2[i] * 909090.909;
    numacc4[i] = numacc3[i] * 10.0;
    numacc2[i + 1] = 1.3;
    numacc3[i + 1] = numacc2[i + 1] * 769230.769;
    numacc4[i + 1] = numacc3[i + 1] * 10.0;
}
}
