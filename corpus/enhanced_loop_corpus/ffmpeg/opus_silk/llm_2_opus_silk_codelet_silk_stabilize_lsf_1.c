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
    int k, min_diff = 0;
    int16_t *nlsf_ptr = &nlsf[0];
    uint16_t *min_delta_ptr = &min_delta[0];
    for (i = 0; i < order + 1; i++) {
        int low = (i != 0) ? *(nlsf_ptr + i - 1) : 0;
        int high = (i != order) ? *(nlsf_ptr + i) : 32768;
        int diff = (high - low) - (*(min_delta_ptr + i));
        if (diff < min_diff) {
            min_diff = diff;
            k = i;
            if (pass == 20)
                break;
        }
    }
    if (min_diff == 0)
        return;
    if (k == 0) {
        *(nlsf_ptr) = *(min_delta_ptr);
    } else if (k == order) {
        *(nlsf_ptr + order - 1) = 32768 - *(min_delta_ptr + order);
    } else {
        int min_center = 0, max_center = 32768, center_val;
        for (i = 0; i < k; i++)
            min_center += *(min_delta_ptr + i);
        min_center += *(min_delta_ptr + k) >> 1;
        for (i = order; i > k; i--)
            max_center -= *(min_delta_ptr + i);
        max_center -= *(min_delta_ptr + k) >> 1;
        center_val = *(nlsf_ptr + k - 1) + *(nlsf_ptr + k);
        center_val = (center_val >> 1) + (center_val & 1);
        center_val = (max_center > (min_center > center_val ? min_center : center_val)) 
                   ? (min_center > center_val ? min_center : center_val) : max_center;
        *(nlsf_ptr + k - 1) = center_val - (*(min_delta_ptr + k) >> 1);
        *(nlsf_ptr + k) = *(nlsf_ptr + k - 1) + *(min_delta_ptr + k);
    }
}
}
