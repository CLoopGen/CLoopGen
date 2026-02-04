#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern  uint16_t min_delta[17];
extern int pass;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (pass = 0; pass < 20 && pass < 21; pass++) {
    int k = 0, min_diff = 32767;
    for (i = 0; i <= order; i++) {
        int low = i ? nlsf[i - 1] : 0;
        int high = (i == order) ? 32768 : nlsf[i];
        int required_gap = min_delta[i];
        int available_gap = high - low;
        int diff = available_gap - required_gap;
        if (diff < min_diff) {
            min_diff = diff;
            k = i;
        }
    }
    if (min_diff >= 0) break;
    switch (k) {
        case 0:
            nlsf[0] = min_delta[0];
            break;
        case 16: // Assuming maximum order is 16
            if (order == 16) {
                nlsf[15] = 32768 - min_delta[16];
            }
            break;
        default:
            int min_center = 0, max_center = 32768;
            for (i = 0; i < k; i++) min_center += min_delta[i];
            min_center += min_delta[k] >> 1;
            for (i = order; i > k; i--) max_center -= min_delta[i];
            max_center -= min_delta[k] >> 1;
            int mid = nlsf[k-1] + nlsf[k];
            int center_val = (mid + 1) / 2;
            if (center_val < min_center) center_val = min_center;
            else if (center_val > max_center) center_val = max_center;
            nlsf[k-1] = center_val - (min_delta[k] >> 1);
            nlsf[k] = nlsf[k-1] + min_delta[k];
            break;
    }
}
}
