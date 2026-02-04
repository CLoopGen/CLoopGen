#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

extern float *divisors;
extern float *workspace;
extern float temp;
extern int i;
extern JCOEFPTR output_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float running_sum = 0.0f;
    for (i = 0; i < 64; i++) {
        temp = workspace[i] * divisors[i] + running_sum;
        running_sum += temp * 0.1f; // Introduce loop-carried dependency (WAW and RAW)
        output_ptr[i] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
    }
}
