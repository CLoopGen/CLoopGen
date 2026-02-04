#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *xcorr;
extern float *y;
extern int len;
extern int max_pitch;
extern int *best_pitch;
extern float best_num[2];
extern float best_den[2];
extern float Syy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_Syy = Syy;
    for (int i = 0; i < max_pitch; i++) {
        float local_num = 0.0F;
        float xcorr16 = xcorr[i] * 9.99999996E-13F;
        if (xcorr[i] > 0) {
            local_num = xcorr16 * xcorr16;
            if ((local_num * best_den[1]) > (best_num[1] * temp_Syy)) {
                if ((local_num * best_den[0]) > (best_num[0] * temp_Syy)) {
                    best_num[1] = best_num[0];
                    best_den[1] = best_den[0];
                    best_pitch[1] = best_pitch[0];
                    best_num[0] = local_num;
                    best_den[0] = temp_Syy;
                    best_pitch[0] = i;
                } else {
                    best_num[1] = local_num;
                    best_den[1] = temp_Syy;
                    best_pitch[1] = i;
                }
            }
        }
        temp_Syy += y[i + len] * y[i + len] - y[i] * y[i];
        temp_Syy = (1.0F > temp_Syy) ? 1.0F : temp_Syy;
    }
    Syy = temp_Syy;
}
