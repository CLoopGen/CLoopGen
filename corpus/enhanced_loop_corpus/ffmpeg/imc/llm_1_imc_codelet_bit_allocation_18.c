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
for (i = 0; i < 32; i += 4) {
    int k;
    for (k = 0; k < 4 && (i + k) < 32; k++) {
        int idx = i + k;
        if (workT[idx] < lowest) {
            lowest = workT[idx];
            low_indx = idx;
        }
    }
}
}
