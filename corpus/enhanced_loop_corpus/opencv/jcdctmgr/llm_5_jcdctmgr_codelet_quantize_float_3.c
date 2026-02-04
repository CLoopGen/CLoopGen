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
    for (i = 0; i < 64; i++) {
        temp = workspace[i] * divisors[i];
        if (temp >= -16384.0f && temp <= 16383.0f) {
            output_ptr[i] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
        } else {
            output_ptr[i] = (temp > 0) ? 16383 : -16384;
        }
    }
}
