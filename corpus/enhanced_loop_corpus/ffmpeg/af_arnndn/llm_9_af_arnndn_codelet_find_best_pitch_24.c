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
for (int i = 0; i < max_pitch / 2; i++) {
    int idx1 = i;
    int idx2 = max_pitch - 1 - i;
    float num1 = 0.0f, num2 = 0.0f;

    if (xcorr[idx1] > 0) {
        float xcorr16 = xcorr[idx1] * 9.99999996E-13F;
        num1 = xcorr16 * xcorr16;
        if ((num1 * best_den[1]) > (best_num[1] * Syy)) {
            if ((num1 * best_den[0]) > (best_num[0] * Syy)) {
                best_num[1] = best_num[0];
                best_den[1] = best_den[0];
                best_pitch[1] = best_pitch[0];
                best_num[0] = num1;
                best_den[0] = Syy;
                best_pitch[0] = idx1;
            } else {
                best_num[1] = num1;
                best_den[1] = Syy;
                best_pitch[1] = idx1;
            }
        }
    }

    if (xcorr[idx2] > 0) {
        float xcorr16 = xcorr[idx2] * 9.99999996E-13F;
        num2 = xcorr16 * xcorr16;
        if ((num2 * best_den[1]) > (best_num[1] * Syy)) {
            if ((num2 * best_den[0]) > (best_num[0] * Syy)) {
                best_num[1] = best_num[0];
                best_den[1] = best_den[0];
                best_pitch[1] = best_pitch[0];
                best_num[0] = num2;
                best_den[0] = Syy;
                best_pitch[0] = idx2;
            } else {
                best_num[1] = num2;
                best_den[1] = Syy;
                best_pitch[1] = idx2;
            }
        }
    }

    Syy += y[idx1 + len] * y[idx1 + len] - y[idx1] * y[idx1];
    if (idx2 >= len) {
        Syy += y[idx2 + len] * y[idx2 + len] - y[idx2] * y[idx2];
    }
    Syy = (1 > Syy) ? 1 : Syy;
}
}
