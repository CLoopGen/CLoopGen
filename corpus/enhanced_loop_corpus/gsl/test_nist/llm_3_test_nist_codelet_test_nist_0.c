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
size_t indices[1000];
for (size_t temp = 0; temp < 1000; temp += 2) {
    indices[temp] = temp;
    indices[temp + 1] = temp + 1;
}
for (i = 0; i < 1000; i += 2) {
    size_t idx = indices[i];
    size_t next_idx = indices[i + 1];
    numacc2[idx] = 1.1000000000000001;
    numacc2[next_idx] = 1.3;
    numacc3[idx] = 1000000.1;
    numacc3[next_idx] = 1000000.3;
    numacc4[idx] = 10000000.1;
    numacc4[next_idx] = 10000000.300000001;
}
}
