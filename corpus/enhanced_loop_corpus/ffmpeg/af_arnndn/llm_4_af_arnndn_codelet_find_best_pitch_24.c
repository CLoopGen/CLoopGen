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
for (int i = 0; i < max_pitch; i++) {
    float num;
    float xcorr16 = xcorr[i];
    if (!(xcorr16 > 0)) continue;
    xcorr16 *= 9.99999996E-13F;
    num = xcorr16 * xcorr16;
    if ((num * best_den[1]) > (best_num[1] * Syy)) {
        if ((num * best_den[0]) > (best_num[0] * Syy)) {
            best_num[1] = best_num[0];
            best_den[1] = best_den[0];
            best_pitch[1] = best_pitch[0];
            best_num[0] = num;
            best_den[0] = Syy;
            best_pitch[0] = i;
        } else {
            best_num[1] = num;
            best_den[1] = Syy;
            best_pitch[1] = i;
        }
    }
    Syy += y[i + len] * y[i + len] - y[i] * y[i];
    Syy = ((1) > (Syy) ? (1) : (Syy));
}
}
