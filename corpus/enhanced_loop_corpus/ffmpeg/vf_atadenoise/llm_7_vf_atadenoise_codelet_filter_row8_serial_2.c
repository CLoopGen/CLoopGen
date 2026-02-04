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
    unsigned int lsumdiff = 0, rsumdiff = 0;
    unsigned int sum = srcx;
    int l = 0, r = 0;

    // Eliminate loop-carried dependencies by precomputing both directions independently
    // and aggregating results only at the end — increases parallelism potential

    // Left pass: mid-1 down to 0
    for (int j = mid - 1; j >= 0; j--) {
        int srcjx = srcf[j][x];
        unsigned int diff = (unsigned int)((srcx > srcjx) ? (srcx - srcjx) : (srcjx - srcx));
        if (diff > thra) break;
        lsumdiff += diff;
        if (lsumdiff > thrb) break;
        sum += srcjx;
        l++;
    }

    // Right pass: mid+1 up to size-1
    // No dependency on left loop state except through final reduction — decoupled
    for (int i = mid + 1; i < size; i++) {
        int srcix = srcf[i][x];
        unsigned int diff = (unsigned int)((srcx > srcix) ? (srcx - srcix) : (srcix - srcx));
        if (diff > thra) break;
        rsumdiff += diff;
        if (rsumdiff > thrb) break;
        sum += srcix;
        r++;
    }

    // Final write with independent computation
    // Reintroduce division with rounding using bit shift in canonical form
    int total_count = r + l + 1;
    dst[x] = (sum + (total_count >> 1)) / total_count;
}
}
