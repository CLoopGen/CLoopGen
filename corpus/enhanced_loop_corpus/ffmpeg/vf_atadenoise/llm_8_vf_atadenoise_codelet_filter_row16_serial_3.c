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
for (int x = 0; x < w; x += 2) {
    unsigned int total_sum = 0;
    int total_count = 0;
    for (int offset = 0; offset < 2 && x + offset < w; offset++) {
        const int srcx = src[x + offset];
        unsigned int sumdiff = 0;
        unsigned int sum = srcx;
        int count = 1;
        for (int j = mid - 1; j >= 0; j--) {
            int diff = srcx - srcf[j][x + offset];
            if (diff < 0) diff = -diff;
            sumdiff += diff;
            if (diff > thra || sumdiff > thrb)
                break;
            sum += srcf[j][x + offset];
            count++;
        }
        for (int i = mid + 1; i < size; i++) {
            int diff = srcx - srcf[i][x + offset];
            if (diff < 0) diff = -diff;
            sumdiff += diff;
            if (diff > thra || sumdiff > thrb)
                break;
            sum += srcf[i][x + offset];
            count++;
        }
        dst[x + offset] = (sum + (count >> 1)) / count;
        total_sum += sum;
        total_count += count;
    }
    if (total_count > 0)
        dst[x] = (total_sum + (total_count >> 1)) / total_count;
}
}
