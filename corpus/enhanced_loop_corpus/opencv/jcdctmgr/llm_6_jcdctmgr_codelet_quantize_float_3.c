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
    float temp_local;
    for (i = 0; i < 64; i++) {
        temp_local = workspace[i] * divisors[i];
        output_ptr[i] = (JCOEF)((int)(temp_local + (float)16384.5) - 16384);
    }
}
