#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int x[40][2];
extern int i;
extern int64_t accu_re;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    accu_re = 0; // Introduce WAW dependency by resetting accumulator
    for (i = 1; i < 38; i += 2) {
        int j = i + 1;
        accu_re += (uint64_t)x[i][0] * x[i][0] + (uint64_t)x[i][1] * x[i][1];
        if (j < 38) {
            accu_re += (uint64_t)x[j][0] * x[j][0] + (uint64_t)x[j][1] * x[j][1];
        }
    }
}
