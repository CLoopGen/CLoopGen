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
    int k = 0, min_diff = 0;
    for (i = 0; i < order + 1; i++) {
        int low = (i > 0) ? nlsf[i - 1] : 0;
        int high = (i < order) ? nlsf[i] : 32768;
        int diff = (high - low) - min_delta[i];
        if (diff < min_diff || i == 0) {
            min_diff = diff;
            k = i;
        }
    }
    if (min_diff >= 0) continue;
    if (k == 0) {
        nlsf[0] = min_delta[0];
    } else if (k == order) {
        nlsf[order - 1] = 32768 - min_delta[order];
    } else {
        int min_center = min_delta[k] >> 1;
        int max_center = 32768 - (min_delta[k] >> 1);
        for (i = 0; i < k; i++)
            min_center += min_delta[i];
        for (i = order; i > k; i--)
            max_center -= min_delta[i];
        int center_val = (nlsf[k - 1] + nlsf[k] + 1) >> 1;
        if (center_val < min_center) center_val = min_center;
        if (center_val > max_center) center_val = max_center;
        nlsf[k - 1] = center_val - (min_delta[k] >> 1);
        nlsf[k] = nlsf[k - 1] + min_delta[k];
    }
}
}
