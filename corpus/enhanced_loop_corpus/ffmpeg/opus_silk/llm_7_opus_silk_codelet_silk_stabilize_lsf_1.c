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
    int updates[16] = {0};
    int update_count = 0;
    for (i = 0; i < order + 1; i++) {
        int low = (i == 0) ? 0 : nlsf[i - 1];
        int high = (i == order) ? 32768 : nlsf[i];
        int required_gap = min_delta[i];
        int actual_gap = high - low;
        int diff = actual_gap - required_gap;
        if (diff < min_diff) {
            min_diff = diff;
            k = i;
        }
    }
    if (min_diff == 0)
        continue;
    if (k == 0) {
        updates[update_count++] = 0;
        nlsf[0] = min_delta[0];
    } else if (k == order) {
        updates[update_count++] = order - 1;
        nlsf[order - 1] = 32768 - min_delta[order];
    } else {
        int left_sum = 0, right_sum = 0;
        for (i = 0; i < k; i++)
            left_sum += min_delta[i];
        left_sum += min_delta[k] >> 1;
        for (i = k + 1; i <= order; i++)
            right_sum += min_delta[i];
        int available_space = 32768 - left_sum - right_sum;
        int adjustment = available_space >> 1;
        int target_center = left_sum + adjustment;
        int current_center = (nlsf[k-1] + nlsf[k]) >> 1;
        if ((nlsf[k-1] + nlsf[k]) & 1)
            current_center++;
        int final_center = current_center;
        if (final_center < left_sum + (min_delta[k] >> 1))
            final_center = left_sum + (min_delta[k] >> 1);
        if (final_center > 32768 - right_sum - (min_delta[k] >> 1))
            final_center = 32768 - right_sum - (min_delta[k] >> 1);
        nlsf[k-1] = final_center - (min_delta[k] >> 1);
        nlsf[k] = nlsf[k-1] + min_delta[k];
        updates[update_count++] = k - 1;
        updates[update_count++] = k;
    }
    if (update_count == 0)
        return;
}
}
