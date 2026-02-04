#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef JLONG DCTELEM;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

extern DCTELEM *divisors;
extern DCTELEM *workspace;
extern int i;
extern DCTELEM temp;
extern JCOEFPTR output_ptr;
extern DCTELEM qval;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    DCTELEM temp_local;
    for (i = 0; i < 64; i++) {
        qval = divisors[i];
        temp_local = workspace[i];
        temp_local += (temp_local < 0) ? (-temp_local + (qval >> 1)) : (qval >> 1);
        if (temp_local >= qval)
            temp_local /= qval;
        else
            temp_local = 0;
        if (workspace[i] < 0)
            temp_local = -temp_local;
        output_ptr[i] = (JCOEF)temp_local;
    }
}
