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
for (i = 0; i < 64; i++) {
    qval = divisors[i];
    temp = workspace[i];
    temp += qval >> 1;
    if (temp >= qval)
        temp /= qval;
    else
        temp = 0;
    if (workspace[i] < 0)
        temp = -temp;
    output_ptr[i] = (JCOEF)temp;
}
}
