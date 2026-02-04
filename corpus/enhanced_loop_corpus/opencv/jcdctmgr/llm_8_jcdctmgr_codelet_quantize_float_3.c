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
    for (i = 0; i < 32; i++) {
        temp = workspace[i] * divisors[i];
        output_ptr[i] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
        temp = workspace[i + 32] * divisors[i + 32];
        output_ptr[i + 32] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
    }
}
