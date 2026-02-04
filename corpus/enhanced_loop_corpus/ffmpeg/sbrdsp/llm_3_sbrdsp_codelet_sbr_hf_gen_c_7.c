#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float (*X_high)[2];
extern  float (*X_low)[2];
extern int start;
extern int end;
extern float alpha[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = start + 2; i < end; i++) {
    int current = i;
    int offset_minus_2 = i - 2;
    int offset_minus_1 = i - 1;
    float temp0 = X_low[offset_minus_2][0];
    float temp1 = X_low[offset_minus_2][1];
    float temp2 = X_low[offset_minus_1][0];
    float temp3 = X_low[offset_minus_1][1];
    float temp4 = X_low[current][0];
    float temp5 = X_low[current][1];

    X_high[current][0] = temp0 * alpha[0] - temp1 * alpha[1] + temp2 * alpha[2] - temp3 * alpha[3] + temp4;
    X_high[current][1] = temp1 * alpha[0] + temp0 * alpha[1] + temp3 * alpha[2] + temp2 * alpha[3] + temp5;
}
}
