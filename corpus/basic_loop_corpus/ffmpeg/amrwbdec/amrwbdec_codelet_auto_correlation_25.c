#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *diff_isf;
extern float mean;
extern int lag;
extern int i;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 7; i < 16 - 2; i++) {
    float prod = (diff_isf[i] - mean) * (diff_isf[i - lag] - mean);
    sum += prod * prod;
}

}
