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
for (int x = 0; x < w; x += 2) {
    unsigned int total_sum = 0;
    int total_count = 0;
    for (int offset = 0; offset < 2 && (x + offset) < w; offset++) {
        const int srcx = src[x + offset];
        unsigned int lsumdiff = 0, rsumdiff = 0;
        unsigned int sum = srcx;
        int l = 0, r = 0;
        for (int j = mid - 1, i = mid + 1; j >= 0 && i < size; j--, i++) {
            const int srcjx = srcf[j][x + offset];
            const int srcix = srcf[i][x + offset];
            unsigned int ldiff = srcx > srcjx ? srcx - srcjx : srcjx - srcx;
            unsigned int rdiff = srcx > srcix ? srcx - srcix : srcix - srcx;
            lsumdiff += ldiff;
            rsumdiff += rdiff;
            if (ldiff > thra || rdiff > thra || lsumdiff > thrb || rsumdiff > thrb)
                break;
            l++;
            r++;
            sum += srcjx + srcix;
        }
        int pixel_count = r + l + 1;
        total_sum += sum + (pixel_count >> 1);
        total_count += pixel_count;
    }
    dst[x] = total_sum / total_count;
    if (x + 1 < w) dst[x + 1] = total_sum / total_count;
}
}
