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
for (i = start; i < end; i++) {
    float temp0 = X_low[i - 2][0] * alpha[0] - X_low[i - 2][1] * alpha[1];
    float temp1 = X_low[i - 1][0] * alpha[2] - X_low[i - 1][1] * alpha[3];
    X_high[i][0] = temp0 + temp1 + X_low[i][0];
    
    float temp2 = X_low[i - 2][1] * alpha[0] + X_low[i - 2][0] * alpha[1];
    float temp3 = X_low[i - 1][1] * alpha[2] + X_low[i - 1][0] * alpha[3];
    X_high[i][1] = temp2 + temp3 + X_low[i][1];
}
}
