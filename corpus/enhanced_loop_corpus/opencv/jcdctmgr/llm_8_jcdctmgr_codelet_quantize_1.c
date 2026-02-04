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
    for (i = 0; i < 32; i++) {
        qval = divisors[i];
        temp = workspace[i];
        if (temp < 0) {
            temp = -temp;
            temp += qval >> 1;
            temp = (temp >= qval) ? temp / qval : 0;
            temp = -temp;
        } else {
            temp += qval >> 1;
            temp = (temp >= qval) ? temp / qval : 0;
        }
        output_ptr[i] = (JCOEF)temp;

        // Second iteration unrolled
        qval = divisors[i + 32];
        temp = workspace[i + 32];
        if (temp < 0) {
            temp = -temp;
            temp += qval >> 1;
            temp = (temp >= qval) ? temp / qval : 0;
            temp = -temp;
        } else {
            temp += qval >> 1;
            temp = (temp >= qval) ? temp / qval : 0;
        }
        output_ptr[i + 32] = (JCOEF)temp;
    }
}
