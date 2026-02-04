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
for (pass = 0; pass < 20; pass++) {
    int k = -1, min_diff = 0;
    int temp_nlsf[16];
    for (int idx = 0; idx < order + 1; idx++) {
        temp_nlsf[idx] = nlsf[idx];
    }
    for (i = 0; i < order + 1; i++) {
        int low = (i > 0) ? temp_nlsf[i - 1] : 0;
        int high = (i < order) ? temp_nlsf[i] : 32768;
        int diff = (high - low) - min_delta[i];
        if (diff < min_diff || k == -1) {
            min_diff = diff;
            k = i;
        }
    }
    if (min_diff >= 0)
        return;
    if (k == 0) {
        temp_nlsf[0] = min_delta[0];
    } else if (k == order) {
        temp_nlsf[order - 1] = 32768 - min_delta[order];
    } else {
        int min_center = 0, max_center = 32768;
        for (i = 0; i < k; i++)
            min_center += min_delta[i];
        min_center += min_delta[k] >> 1;
        for (i = order; i > k; i--)
            max_center -= min_delta[i];
        max_center -= min_delta[k] >> 1;
        int center_val = (temp_nlsf[k - 1] + temp_nlsf[k]) >> 1;
        if ((temp_nlsf[k - 1] + temp_nlsf[k]) & 1)
            center_val++;
        if (center_val < min_center) center_val = min_center;
        if (center_val > max_center) center_val = max_center;
        temp_nlsf[k - 1] = center_val - (min_delta[k] >> 1);
        temp_nlsf[k] = temp_nlsf[k - 1] + min_delta[k];
    }
    for (i = 0; i < order; i++) {
        nlsf[i] = temp_nlsf[i];
    }
}
}
