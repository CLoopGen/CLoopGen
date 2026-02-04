#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mid;
extern int size;
extern int thra;
extern int thrb;
extern  uint16_t *src;
extern  uint16_t **srcf;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int x = 0; x < w; x++) {
    const int srcx = src[x];
    unsigned int total_sum = srcx;
    int total_count = 1;
    unsigned int accumulated_diff = 0;

    for (int offset = 1; offset < size && offset <= mid; offset++) {
        int valid_updates = 0;

        if (mid - offset >= 0) {
            int left_val = srcf[mid - offset][x];
            unsigned int diff = (srcx >= left_val) ? (srcx - left_val) : (left_val - srcx);
            if (diff <= thra && accumulated_diff + diff <= thrb) {
                total_sum += left_val;
                total_count++;
                accumulated_diff += diff;
                valid_updates++;
            }
        }

        if (mid + offset < size) {
            int right_val = srcf[mid + offset][x];
            unsigned int diff = (srcx >= right_val) ? (srcx - right_val) : (right_val - srcx);
            if (diff <= thra && accumulated_diff + diff <= thrb) {
                total_sum += right_val;
                total_count++;
                accumulated_diff += diff;
                valid_updates++;
            }
        }

        if (valid_updates == 0) break;
    }

    dst[x] = (total_sum + (total_count >> 1)) / total_count;
}
}
