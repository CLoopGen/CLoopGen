#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j += 2) {
    if (j + 1 < h) {
        for (i = 0; i < w; i++) {
            int base_idx_curr = srcStride * 0 + i;
            int base_idx_prev = srcStride * -1 + i;
            int base_idx_next = srcStride * 1 + i;
            int base_idx_next2 = srcStride * 2 + i;

            int sum_curr = 72 * src[base_idx_curr] - 12 * (src[base_idx_curr - 1] + src[base_idx_curr + 1]) + src[base_idx_curr - 2] + src[base_idx_curr + 2];
            int sum_prev = -6 * (src[base_idx_prev] + src[base_idx_prev - 1] + src[base_idx_prev + 1]) + src[base_idx_prev - 2] + src[base_idx_prev + 2];
            int sum_next = 36 * src[base_idx_next] - 6 * (src[base_idx_next - 1] + src[base_idx_next + 1]);
            int sum_next2 = -6 * src[base_idx_next2] + src[base_idx_next2 - 1] + src[base_idx_next2 + 1];

            int total = (sum_curr + sum_prev + sum_next + sum_next2 + 128) >> 8;
            dst[i] = (cm[total] + 1) >> 1;

            int base_idx_curr_j1 = srcStride * 1 + i;
            int base_idx_prev_j1 = srcStride * 0 + i;
            int base_idx_next_j1 = srcStride * 2 + i;
            int base_idx_next2_j1 = srcStride * 3 + i;

            int sum_curr_j1 = 72 * src[base_idx_curr_j1] - 12 * (src[base_idx_curr_j1 - 1] + src[base_idx_curr_j1 + 1]) + src[base_idx_curr_j1 - 2] + src[base_idx_curr_j1 + 2];
            int sum_prev_j1 = -6 * (src[base_idx_prev_j1] + src[base_idx_prev_j1 - 1] + src[base_idx_prev_j1 + 1]) + src[base_idx_prev_j1 - 2] + src[base_idx_prev_j1 + 2];
            int sum_next_j1 = 36 * src[base_idx_next_j1] - 6 * (src[base_idx_next_j1 - 1] + src[base_idx_next_j1 + 1]);
            int sum_next2_j1 = -6 * src[base_idx_next2_j1] + src[base_idx_next2_j1 - 1] + src[base_idx_next2_j1 + 1];

            int total_j1 = (sum_curr_j1 + sum_prev_j1 + sum_next_j1 + sum_next2_j1 + 128) >> 8;
            dst[dstStride + i] = (cm[total_j1] + 1) >> 1;
        }
        dst += 2 * dstStride;
        src += 2 * srcStride;
    } else {
        for (i = 0; i < w; i++) {
            dst[i] = (((dst[i]) + cm[(src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i + 1] - 6 * src[srcStride * -1 + i] + src[srcStride * -1 + i + 2] + -12 * src[srcStride * 0 + i - 1] + 144 * src[srcStride * 0 + i + 1] + 72 * src[srcStride * 0 + i] - 12 * src[srcStride * 0 + i + 2] + -6 * src[srcStride * 1 + i - 1] + 72 * src[srcStride * 1 + i + 1] + 36 * src[srcStride * 1 + i] - 6 * src[srcStride * 1 + i + 2] + src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i + 1] - 6 * src[srcStride * 2 + i] + src[srcStride * 2 + i + 2] + 128) >> 8] + 1) >> 1);
        }
        dst += dstStride;
        src += srcStride;
    }
}
}
