#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int x[40][2];
extern int lag;
extern int i;
extern int64_t accu_re;
extern int64_t accu_im;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 39; i++) {
    int idx1 = i;
    int idx2 = i + lag;
    accu_re += (uint64_t)(x[idx1][0] * x[idx2][0] + x[idx1][1] * x[idx2][1]);
    accu_im += (uint64_t)(x[idx1][0] * x[idx2][1] - x[idx1][1] * x[idx2][0]);
}
}
