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
int j, k;
for (j = 0; j < 1; j++) {
    for (k = 0; k < 10; k++) {
        if (k == i) {
            lsfnew[k] = lsf_history[k] * 0.33000000000000002 + lsf_tmp[k] + mean_lsf[k];
        }
    }
}
}
