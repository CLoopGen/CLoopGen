#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float output[32][4];
extern ptrdiff_t len;
extern float AL1;
extern float AL2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 12; i < len - 1; i++) {
    float temp0 = output[i][3] * AL1;
    float temp1 = output[i + 1][0] * AL1;
    float temp2 = output[i][2] * AL2;
    float temp3 = output[i + 1][1] * AL2;

    output[i][3] += temp1 - temp0;
    output[i + 1][0] -= temp1 + temp0;
    output[i][2] += temp3 - temp2;
    output[i + 1][1] -= temp3 + temp2;
}
}
