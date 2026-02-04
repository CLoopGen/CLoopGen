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
    for (i = 0; i < 64; i += 4) {
        temp = workspace[i] * divisors[i] + workspace[i] / (divisors[i] + 1e-5f);
        output_ptr[i] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
        temp = workspace[i+1] * divisors[i+1] + workspace[i+1] / (divisors[i+1] + 1e-5f);
        output_ptr[i+1] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
        temp = workspace[i+2] * divisors[i+2] + workspace[i+2] / (divisors[i+2] + 1e-5f);
        output_ptr[i+2] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
        temp = workspace[i+3] * divisors[i+3] + workspace[i+3] / (divisors[i+3] + 1e-5f);
        output_ptr[i+3] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
    }
}
