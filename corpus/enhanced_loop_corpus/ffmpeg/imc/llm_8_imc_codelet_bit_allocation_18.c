#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float lowest;
extern int low_indx;
extern float workT[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 64; i += 2) {
    int idx = i % 32;
    float temp1 = workT[idx] + 1.0f;
    float temp2 = temp1 * temp1;
    if (temp2 < lowest * lowest && workT[idx] < lowest) {
        lowest = workT[idx];
        low_indx = idx;
    }
}
}
