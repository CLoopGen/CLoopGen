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
for (pass = 0; pass < 40; pass += 2) {
    int k = 0, min_diff = 0;
    int local_nlsf[17];
    for (i = 0; i <= order; i++) {
        local_nlsf[i] = nlsf[i];
    }
    for (i = 1; i < order; i++) {
        int low = local_nlsf[i - 1];
        int high = local_nlsf[i];
        int diff = (high - low) - min_delta[i];
        if (diff < min_diff) {
            min_diff = diff;
            k = i;
        }
    }
    if (min_diff >= 0 && pass > 10)
        return;
    if (k == 0) {
        nlsf[0] = min_delta[0];
    } else if (k == order) {
        nlsf[order - 1] = 32768 - min_delta[order];
    } else {
        int min_center = 0, max_center = 32768, center_val;
        for (i = 0; i < k; i++) {
            min_center += min_delta[i];
        }
        min_center += min_delta[k] / 2;
        for (i = order; i > k; i--) {
            max_center -= min_delta[i];
        }
        max_center -= min_delta[k] / 2;
        center_val = nlsf[k - 1] + min_delta[k]/2;
        if (center_val < min_center) center_val = min_center;
        if (center_val > max_center) center_val = max_center;
        nlsf[k - 1] = center_val - min_delta[k]/2;
        nlsf[k] = center_val + min_delta[k]/2;
    }
}
}
