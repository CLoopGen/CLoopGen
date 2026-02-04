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
    unsigned int total_sum = srcx;
    int valid_count = 1;
    unsigned int accumulated_diff = 0;

    for (int k = 0; k < size; k++) {
        if (k == mid) continue;

        const int neighbor_val = srcf[k][x];
        unsigned int diff = (srcx >= neighbor_val) ? (srcx - neighbor_val) : (neighbor_val - srcx);
        accumulated_diff += diff;

        if (diff <= thra && accumulated_diff <= thrb) {
            total_sum += neighbor_val;
            valid_count++;
        } else {
            break;
        }
    }

    dst[x] = (total_sum + (valid_count >> 1)) / valid_count;
}
}
