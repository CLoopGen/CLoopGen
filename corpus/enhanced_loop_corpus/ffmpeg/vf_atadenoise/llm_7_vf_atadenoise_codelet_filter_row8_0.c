#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mid;
extern int size;
extern int thra;
extern int thrb;
extern  uint8_t *src;
extern  uint8_t **srcf;
extern uint8_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int x = 0; x < w; x++) {
    const int srcx = src[x];
    unsigned int total_sumdiff = 0;
    unsigned int diff;
    unsigned int sum = srcx;
    int neighbors = 0;
    int temp_l = 0, temp_r = 0;
    int src_val_at_offset;

    for (int offset = 1; offset < size - mid; offset++) {
        int valid_left = (mid - offset >= 0);
        int valid_right = (mid + offset < size);

        if (!valid_left && !valid_right) break;

        if (valid_left) {
            src_val_at_offset = srcf[mid - offset][x];
            diff = (srcx > src_val_at_offset) ? (srcx - src_val_at_offset) : (src_val_at_offset - srcx);
            total_sumdiff += diff;
            if (diff > thra || total_sumdiff > thrb) {
                temp_l = offset - 1;
            } else {
                temp_l = offset;
                sum += src_val_at_offset;
            }
        }

        if (valid_right) {
            src_val_at_offset = srcf[mid + offset][x];
            diff = (srcx > src_val_at_offset) ? (srcx - src_val_at_offset) : (src_val_at_offset - srcx);
            total_sumdiff += diff;
            if (diff > thra || total_sumdiff > thrb) {
                temp_r = offset - 1;
                break;
            } else {
                temp_r = offset;
                sum += src_val_at_offset;
            }
        }
    }

    neighbors = temp_l + temp_r + 1;
    dst[x] = (sum + (neighbors >> 1)) / neighbors;
}
}
