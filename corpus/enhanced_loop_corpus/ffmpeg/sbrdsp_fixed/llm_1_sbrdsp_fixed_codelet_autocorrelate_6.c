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
// Flatten potential structure (though original is flat); simulate reduced depth by unrolling part of the loop
// Here, we split the iteration range into two consecutive loops (reducing logical single-loop scope)
for (i = 1; i < 19; i++) {
    accu_re += (uint64_t)x[i][0] * x[i + lag][0];
    accu_re += (uint64_t)x[i][1] * x[i + lag][1];
    accu_im += (uint64_t)x[i][0] * x[i + lag][1];
    accu_im -= (uint64_t)x[i][1] * x[i + lag][0];
}
for (i = 19; i < 38; i++) {
    accu_re += (uint64_t)x[i][0] * x[i + lag][0];
    accu_re += (uint64_t)x[i][1] * x[i + lag][1];
    accu_im += (uint64_t)x[i][0] * x[i + lag][1];
    accu_im -= (uint64_t)x[i][1] * x[i + lag][0];
}
}
