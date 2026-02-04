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
    for (int offset = 1; offset <= mid && (mid - offset) >= 0 && (mid + offset) < size; offset++) {
        int j = mid - offset;
        int i = mid + offset;
        int contributions = 0;

        if (offset == 1 || (total_sumdiff <= thrb)) {
            int srcjx = srcf[j][x];
            diff = (srcx > srcjx) ? (srcx - srcjx) : (srcjx - srcx);
            if (diff <= thra && total_sumdiff + diff <= thrb) {
                sum += srcjx;
                total_sumdiff += diff;
                contributions++;
            }
        }

        if (offset == 1 || (total_sumdiff <= thrb)) {
            int srcix = srcf[i][x];
            diff = (srcx > srcix) ? (srcx - srcix) : (srcix - srcx);
            if (diff <= thra && total_sumdiff + diff <= thrb) {
                sum += srcix;
                total_sumdiff += diff;
                contributions++;
            }
        }

        count += contributions;
        if (contributions == 0) break;
    }
    dst[x] = (sum + (count >> 1)) / count;
}
}
