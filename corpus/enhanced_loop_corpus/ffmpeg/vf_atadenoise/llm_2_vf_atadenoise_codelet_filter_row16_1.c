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
    const int srcx0 = src[x];
    unsigned int lsumdiff0 = 0, rsumdiff0 = 0;
    unsigned int ldiff0, rdiff0;
    unsigned int sum0 = srcx0;
    int l0 = 0, r0 = 0;
    int srcjx0, srcix0;

    unsigned int lsumdiff1 = 0, rsumdiff1 = 0;
    unsigned int ldiff1, rdiff1;
    unsigned int sum1 = 0;
    int l1 = 0, r1 = 0;
    int srcjx1, srcix1;
    const int srcx1 = (x + 1 < w) ? src[x + 1] : srcx0;
    sum1 = srcx1;

    for (int j = mid - 1, i = mid + 1; j >= 0 && i < size; j--, i++) {
        srcjx0 = srcf[j][x];
        ldiff0 = ((srcx0 - srcjx0) >= 0 ? (srcx0 - srcjx0) : (-(srcx0 - srcjx0)));
        lsumdiff0 += ldiff0;
        if (ldiff0 > thra || lsumdiff0 > thrb)
            break;
        l0++;
        sum0 += srcjx0;

        srcix0 = srcf[i][x];
        rdiff0 = ((srcx0 - srcix0) >= 0 ? (srcx0 - srcix0) : (-(srcx0 - srcix0)));
        rsumdiff0 += rdiff0;
        if (rdiff0 > thra || rsumdiff0 > thrb)
            break;
        r0++;
        sum0 += srcix0;

        if (x + 1 < w) {
            srcjx1 = srcf[j][x + 1];
            ldiff1 = ((srcx1 - srcjx1) >= 0 ? (srcx1 - srcjx1) : (-(srcx1 - srcjx1)));
            lsumdiff1 += ldiff1;
            if (ldiff1 > thra || lsumdiff1 > thrb)
                continue;
            l1++;
            sum1 += srcjx1;

            srcix1 = srcf[i][x + 1];
            rdiff1 = ((srcx1 - srcix1) >= 0 ? (srcx1 - srcix1) : (-(srcx1 - srcix1)));
            rsumdiff1 += rdiff1;
            if (rdiff1 > thra || rsumdiff1 > thrb)
                continue;
            r1++;
            sum1 += srcix1;
        }
    }
    dst[x] = (sum0 + ((r0 + l0 + 1) >> 1)) / (r0 + l0 + 1);
    if (x + 1 < w) {
        dst[x + 1] = (sum1 + ((r1 + l1 + 1) >> 1)) / (r1 + l1 + 1);
    }
}
}
