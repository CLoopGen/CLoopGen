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
// Outer loop split: process left and right neighborhoods in separate phases
// Phase 1: collect valid indices and sums from left side
int *valid_left = (int*)alloca(w * size * sizeof(int));
int *left_count = (int*)alloca(w * sizeof(int));
unsigned int *left_sumdiffs = (unsigned int*)alloca(w * sizeof(unsigned int));

for (int x = 0; x < w; x++) {
    left_count[x] = 0;
    left_sumdiffs[x] = 0;
    const int srcx = src[x];
    unsigned int lsumdiff = 0;
    for (int j = mid - 1; j >= 0; j--) {
        int srcjx = srcf[j][x];
        unsigned int ldiff = ((srcx - srcjx) >= 0 ? (srcx - srcjx) : (-(srcx - srcjx)));
        lsumdiff += ldiff;
        if (ldiff > thra || lsumdiff > thrb)
            break;
        valid_left[x * size + left_count[x]++] = srcjx;
    }
    left_sumdiffs[x] = lsumdiff;
}

// Phase 2: process each x again with right-side accumulation and combine results
for (int x = 0; x < w; x++) {
    const int srcx = src[x];
    unsigned int rsumdiff = 0;
    unsigned int sum = srcx;
    int r = 0;
    int srcix;

    // Add all valid left contributions
    for (int k = 0; k < left_count[x]; k++) {
        sum += valid_left[x * size + k];
    }
    int l = left_count[x];

    // Traverse right side
    for (int i = mid + 1; i < size; i++) {
        srcix = srcf[i][x];
        unsigned int rdiff = ((srcx - srcix) >= 0 ? (srcx - srcix) : (-(srcx - srcix)));
        rsumdiff += rdiff;
        if (rdiff > thra || rsumdiff > thrb)
            break;
        r++;
        sum += srcix;
    }
    dst[x] = (sum + ((r + l + 1) >> 1)) / (r + l + 1);
}
}
