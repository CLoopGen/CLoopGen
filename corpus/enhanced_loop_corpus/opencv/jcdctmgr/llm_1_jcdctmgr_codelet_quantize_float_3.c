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
    i = 0;
    for (int outer = 0; outer < 1; outer++) {
        for (int inner = 0; inner < 64; inner++) {
            temp = workspace[i] * divisors[i];
            output_ptr[i] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
            i++;
        }
    }
}
