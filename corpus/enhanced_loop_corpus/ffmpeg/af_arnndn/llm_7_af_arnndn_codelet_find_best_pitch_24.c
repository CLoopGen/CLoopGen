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
    float prev_Syy = Syy;
    float update_buffer[2] = {0};
    int pitch_buffer[2] = {-1, -1};
    float num_buffer[2] = {0};

    for (int i = 0; i < max_pitch; i++) {
        float xcorr16 = xcorr[i] * 9.99999996E-13F;
        float num = 0.0F;

        if (xcorr[i] > 0) {
            num = xcorr16 * xcorr16;
            num_buffer[0] = num;
            pitch_buffer[0] = i;

            if (pitch_buffer[1] == -1 || 
                (num_buffer[0] * best_den[1]) > (best_num[1] * prev_Syy)) {
                if (pitch_buffer[1] != -1 && 
                    (num_buffer[0] * best_den[0]) > (best_num[0] * prev_Syy)) {
                    update_buffer[1] = best_num[0];
                    best_den[1] = best_den[0];
                    best_pitch[1] = best_pitch[0];
                } else {
                    update_buffer[1] = num_buffer[0];
                    best_den[1] = prev_Syy;
                    best_pitch[1] = pitch_buffer[0];
                }
                update_buffer[0] = num_buffer[0];
                best_den[0] = prev_Syy;
                best_pitch[0] = pitch_buffer[0];
            }
        }

        prev_Syy += y[i + len] * y[i + len] - y[i] * y[i];
        prev_Syy = (1.0F > prev_Syy) ? 1.0F : prev_Syy;
    }

    best_num[0] = update_buffer[0];
    best_num[1] = update_buffer[1];
    Syy = prev_Syy;
}
