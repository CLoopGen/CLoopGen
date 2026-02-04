#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int32_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    const int t0 = input[8*i+0] + input[8*i+1];
    const int t1 = input[8*i+0] - input[8*i+1];
    const int t2 = input[8*i+2] + input[8*i+3];
    const int t3 = input[8*i+2] - input[8*i+3];
    const int t4 = input[8*i+4] + input[8*i+5];
    const int t5 = input[8*i+4] - input[8*i+5];
    const int t6 = input[8*i+6] + input[8*i+7];
    const int t7 = input[8*i+6] - input[8*i+7];

    temp[8*i+0] = t0 + t2;
    temp[8*i+1] = t0 - t2;
    temp[8*i+2] = t1 - t3;
    temp[8*i+3] = t1 + t3;
    temp[8*i+4] = t4 + t6;
    temp[8*i+5] = t4 - t6;
    temp[8*i+6] = t5 - t7;
    temp[8*i+7] = t5 + t7;
}
}
