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
    unsigned int ldiff = 0, rdiff = 0;
    unsigned int sum = srcx;
    int l = 0, r = 0;
    int srcjx, srcix;
    int lj = mid - 1, ri = mid + 1;
    // Unroll control: process left and right independently with separate conditions
    for (int step = 0; step < size; step++) {
        int updated = 0;

        // Process left side if still valid
        if (lj >= 0) {
            srcjx = srcf[lj][x];
            ldiff = (srcx >= srcjx) ? (srcx - srcjx) : (srcjx - srcx);
            lsumdiff += ldiff;
            if (ldiff <= thra && lsumdiff <= thrb) {
                l++;
                sum += srcjx;
            } else {
                lj = -1; // disable further left processing
            }
            lj--;
            updated = 1;
        }

        // Process right side if still valid
        if (ri < size) {
            srcix = srcf[ri][x];
            rdiff = (srcx >= srcix) ? (srcx - srcix) : (srcix - srcx);
            rsumdiff += rdiff;
            if (rdiff <= thra && rsumdiff <= thrb) {
                r++;
                sum += srcix;
            } else {
                ri = size; // disable further right processing
            }
            ri++;
            updated = 1;
        }

        // Terminate early if no updates occurred
        if (!updated) break;
    }
    dst[x] = (sum + ((r + l + 1) >> 1)) / (r + l + 1);
}
}
