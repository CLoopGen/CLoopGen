#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float mean_lsf[10];
extern float *lsfnew;
extern float *lsf_history;
extern int i;
extern float lsf_tmp[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[10];
    for (i = 0; i < 10; i++) {
        temp[i] = lsf_history[i] * 0.33000000000000002 + mean_lsf[i];
    }
    for (i = 0; i < 10; i++) {
        lsfnew[i] = temp[i] + lsf_tmp[i];
    }
}
