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
    unsigned int ldiff, rdiff;
    unsigned int sum = srcx;
    int l = 0, r = 0;
    int srcjx, srcix;
    for (int j = mid - 1, i = mid + 1; j >= 0 && i < size; j--, i++) {
        srcjx = srcf[j][x];
        ldiff = ((srcx - srcjx) >= 0 ? (srcx - srcjx) : (-(srcx - srcjx)));
        lsumdiff += ldiff;
        if (ldiff > thra || lsumdiff > thrb)
            goto right_check;
        l++;
        sum += srcjx;

        srcix = srcf[i][x];
        rdiff = ((srcx - srcix) >= 0 ? (srcx - srcix) : (-(srcx - srcix)));
        rsumdiff += rdiff;
        if (rdiff > thra || rsumdiff > thrb)
            goto end_loop;
        r++;
        sum += srcix;
        continue;

    right_check:
        srcix = srcf[i][x];
        rdiff = ((srcx - srcix) >= 0 ? (srcx - srcix) : (-(srcx - srcix)));
        rsumdiff += rdiff;
        if (rdiff <= thra && rsumdiff <= thrb) {
            r++;
            sum += srcix;
        }
        goto end_loop;

    end_loop:;
    }
    dst[x] = (sum + ((r + l + 1) >> 1)) / (r + l + 1);
}
}
