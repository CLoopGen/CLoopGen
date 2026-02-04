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
    Syy += y[i + len] * y[i + len] - y[i] * y[i];
    Syy = (Syy < 1.0f) ? 1.0f : Syy;
    if (xcorr[i] <= 0) {
        continue;
    }
    float xcorr16 = xcorr[i] * 9.99999996E-13F;
    float num = xcorr16 * xcorr16;
    int update_second = (num * best_den[1]) > (best_num[1] * Syy);
    int update_first = update_second && ((num * best_den[0]) > (best_num[0] * Syy));
    if (update_first) {
        best_num[1] = best_num[0];
        best_den[1] = best_den[0];
        best_pitch[1] = best_pitch[0];
    }
    if (update_second) {
        best_num[update_first ? 0 : 1] = num;
        best_den[update_first ? 0 : 1] = Syy;
        best_pitch[update_first ? 0 : 1] = i;
    }
}
}
