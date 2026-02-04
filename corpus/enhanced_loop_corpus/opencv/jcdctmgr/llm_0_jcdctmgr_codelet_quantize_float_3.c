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
    for (int j = 0; j < 8; j++) {
        for (i = j * 8; i < (j + 1) * 8; i++) {
            temp = workspace[i] * divisors[i];
            output_ptr[i] = (JCOEF)((int)(temp + (float)16384.5) - 16384);
        }
    }
}
