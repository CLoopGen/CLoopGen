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
for (i = 1; i < 38; i++) {
    int skip_update = (i % 2 == 0);
    if (!skip_update) {
        accu_re += (uint64_t)x[i][0] * x[i + lag][0];
        accu_re += (uint64_t)x[i][1] * x[i + lag][1];
        accu_im += (uint64_t)x[i][0] * x[i + lag][1];
        accu_im -= (uint64_t)x[i][1] * x[i + lag][0];
    }
}
}
