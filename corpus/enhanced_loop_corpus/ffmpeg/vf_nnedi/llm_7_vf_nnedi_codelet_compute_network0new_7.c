#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *wf;
extern float vals[8];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float temp_vals[4];
for (i = 0; i < 4; i++) {
    float sum = 0.F;
    for (j = 0; j < 4; j++)
        sum += vals[j] * wf[8 + i + (j << 2)];
    temp_vals[i] = sum + wf[24 + i]; // Eliminate loop-carried dependence by using local temp array
}
// Store results after full computation to remove WAW and enable better optimization
for (i = 0; i < 4; i++) {
    vals[4 + i] = temp_vals[i];
}

}
