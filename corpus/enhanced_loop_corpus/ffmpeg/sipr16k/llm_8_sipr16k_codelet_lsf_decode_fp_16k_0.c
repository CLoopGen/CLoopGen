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
    for (i = 0; i < 8; i += 2) {
        float w = qu[ma_pred];
        float iw = 1.0f - w;
        isp_new[i]     = iw * isp_q[i] + w * lsf_history[i] + mean_lsf_16k[i];
        if (i + 1 < 16) {
            isp_new[i+1] = iw * isp_q[i+1] + w * lsf_history[i+1] + mean_lsf_16k[i+1];
        }
    }
}
