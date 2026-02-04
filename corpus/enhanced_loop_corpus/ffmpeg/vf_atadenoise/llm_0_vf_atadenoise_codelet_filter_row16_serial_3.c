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
    unsigned int lsumdiff = 0, rsumdiff = 0;
    unsigned int ldiff, rdiff;
    unsigned int sum = srcx;
    int l = 0, r = 0;
    int srcjx, srcix;

    // Combined bidirectional search using a single loop with offset indexing
    for (int offset = 1; offset < size; offset++) {
        // Left side: mid - offset
        if (mid - offset >= 0) {
            srcjx = srcf[mid - offset][x];
            ldiff = ((srcx - srcjx) >= 0 ? (srcx - srcjx) : (-(srcx - srcjx)));
            lsumdiff += ldiff;
            if (ldiff > thra || lsumdiff > thrb) {
                // Stop accumulating left
            } else {
                l++;
                sum += srcjx;
            }
        }

        // Right side: mid + offset
        if (mid + offset < size) {
            srcix = srcf[mid + offset][x];
            rdiff = ((srcx - srcix) >= 0 ? (srcx - srcix) : (-(srcx - srcix)));
            rsumdiff += rdiff;
            if (rdiff > thra || rsumdiff > thrb) {
                // Stop accumulating right
            } else {
                r++;
                sum += srcix;
            }
        }
    }
    dst[x] = (sum + ((r + l + 1) >> 1)) / (r + l + 1);
}
}
