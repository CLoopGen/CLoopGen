#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float qu[2];
extern  float mean_lsf_16k[16];
extern float *lsf_history;
extern float *isp_new;
extern int ma_pred;
extern int i;
extern float isp_q[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 16; i++) {
            isp_new[i] = (1 - qu[ma_pred]) * isp_q[i] + qu[ma_pred] * lsf_history[i] + mean_lsf_16k[i];
        }
    }
}
