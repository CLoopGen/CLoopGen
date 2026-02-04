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
float prev_x0 = (i > start) ? X_low[start - 1][0] : 0.0f;
float prev_x1 = (i > start) ? X_low[start - 1][1] : 0.0f;
for (i = start; i < end; i++) {
    float curr0 = X_low[i][0];
    float curr1 = X_low[i][1];
    
    X_high[i][0] = X_low[i - 2][0] * alpha[0] - X_low[i - 2][1] * alpha[1] + prev_x0 * alpha[2] - X_low[i - 1][1] * alpha[3] + curr0;
    X_high[i][1] = X_low[i - 2][1] * alpha[0] + X_low[i - 2][0] * alpha[1] + prev_x1 * alpha[2] + X_low[i - 1][0] * alpha[3] + curr1;
    
    prev_x0 = curr0;
    prev_x1 = curr1;
}
}
