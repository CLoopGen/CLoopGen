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

    ptrdiff_t *index_map = alloca(size * sizeof(ptrdiff_t));
    for (int k = 0; k < size; k++) {
        index_map[k] = k;
    }

    for (int step = 1; step <= mid; step++) {
        int j = mid - step;
        int i = mid + step;
        if (j < 0 || i >= size) break;

        srcjx = srcf[index_map[j]][x];
        ldiff = (srcx >= srcjx) ? (srcx - srcjx) : (srcjx - srcx);
        lsumdiff += ldiff;
        if (ldiff > thra || lsumdiff > thrb) break;
        l++;
        sum += srcjx;

        srcix = srcf[index_map[i]][x];
        rdiff = (srcx >= srcix) ? (srcx - srcix) : (srcix - srcx);
        rsumdiff += rdiff;
        if (rdiff > thra || rsumdiff > thrb) break;
        r++;
        sum += srcix;
    }
    dst[x] = (sum + ((r + l + 1) >> 1)) / (r + l + 1);
}
}
