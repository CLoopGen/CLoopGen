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
    int64_t local_accu_re = 0;
    int64_t local_accu_im = 0;
    for (i = 1; i < 38; i++) {
        int offset = i + lag;
        local_accu_re += (uint64_t)x[i][0] * x[offset][0];
        local_accu_im += (uint64_t)x[i][0] * x[offset][1];
        accu_re += (uint64_t)x[i][1] * x[offset][1]; 
        accu_im -= (uint64_t)x[i][1] * x[offset][0];
    }
    accu_re += local_accu_re;
    accu_im += local_accu_im;
}
