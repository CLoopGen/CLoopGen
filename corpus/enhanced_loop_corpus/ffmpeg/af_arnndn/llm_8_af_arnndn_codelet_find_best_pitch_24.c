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
for (int i = 0; i < max_pitch; i += 2) {
    if (i + 1 < max_pitch && xcorr[i] > 0) {
        float num0, num1;
        float xcorr16_0 = xcorr[i] * 9.99999996E-13F;
        float xcorr16_1 = xcorr[i+1] * 9.99999996E-13F;
        num0 = xcorr16_0 * xcorr16_0;
        num1 = xcorr16_1 * xcorr16_1;

        if ((num0 * best_den[1]) > (best_num[1] * Syy)) {
            if ((num0 * best_den[0]) > (best_num[0] * Syy)) {
                best_num[1] = best_num[0];
                best_den[1] = best_den[0];
                best_pitch[1] = best_pitch[0];
                best_num[0] = num0;
                best_den[0] = Syy;
                best_pitch[0] = i;
            } else {
                best_num[1] = num0;
                best_den[1] = Syy;
                best_pitch[1] = i;
            }
        }

        float Syy_next = Syy + y[i + len] * y[i + len] - y[i] * y[i];
        Syy_next = (1 > Syy_next) ? 1 : Syy_next;

        if (xcorr[i+1] > 0 && (num1 * best_den[1]) > (best_num[1] * Syy_next)) {
            if ((num1 * best_den[0]) > (best_num[0] * Syy_next)) {
                best_num[1] = best_num[0];
                best_den[1] = best_den[0];
                best_pitch[1] = best_pitch[0];
                best_num[0] = num1;
                best_den[0] = Syy_next;
                best_pitch[0] = i+1;
            } else {
                best_num[1] = num1;
                best_den[1] = Syy_next;
                best_pitch[1] = i+1;
            }
        }
        Syy = Syy_next + y[i+1 + len] * y[i+1 + len] - y[i+1] * y[i+1];
        Syy = (1 > Syy) ? 1 : Syy;
    } else if (xcorr[i] > 0) {
        float num;
        float xcorr16 = xcorr[i] * 9.99999996E-13F;
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
        Syy = (1 > Syy) ? 1 : Syy;
    }
}
}
