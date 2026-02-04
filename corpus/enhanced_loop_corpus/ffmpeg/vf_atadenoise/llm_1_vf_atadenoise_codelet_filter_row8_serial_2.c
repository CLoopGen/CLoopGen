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
    int count = 1;
    for (int offset = 1; mid - offset >= 0 || mid + offset < size; offset++) {
        if (mid - offset >= 0) {
            int j = mid - offset;
            int srcjx = srcf[j][x];
            diff = ((srcx - srcjx) >= 0 ? (srcx - srcjx) : (-(srcx - srcjx)));
            total_sumdiff += diff;
            if (diff > thra || total_sumdiff > thrb) {
            } else {
                sum += srcjx;
                count++;
            }
        }
        if (mid + offset < size) {
            int i = mid + offset;
            int srcix = srcf[i][x];
            diff = ((srcx - srcix) >= 0 ? (srcx - srcix) : (-(srcx - srcix)));
            total_sumdiff += diff;
            if (diff > thra || total_sumdiff > thrb) {
            } else {
                sum += srcix;
                count++;
            }
        }
    }
    dst[x] = (sum + (count >> 1)) / count;
}
}
