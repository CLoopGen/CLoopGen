#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int x[40][2];
extern int i;
extern int64_t accu_re;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 38; i++) {
    accu_re += (uint64_t)x[i][0] * x[i][0];
    if (x[i][1] > 0) {
        accu_re += (uint64_t)x[i][1] * x[i][1];
    }
}
}
