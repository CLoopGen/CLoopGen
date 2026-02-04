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
    const int srcx0 = src[x];
    const int srcx1 = (x + 1 < w) ? src[x + 1] : srcx0;
    unsigned int lsumdiff0 = 0, rsumdiff0 = 0;
    unsigned int lsumdiff1 = 0, rsumdiff1 = 0;
    unsigned int ldiff0, rdiff0, ldiff1, rdiff1;
    unsigned int sum0 = srcx0, sum1 = srcx1;
    int l0 = 0, r0 = 0, l1 = 0, r1 = 0;
    int srcjx0, srcjx1, srcix0, srcix1;

    for (int j = mid - 1, i = mid + 1; j >= 0 && i < size; j--, i++) {
        srcjx0 = srcf[j][x];
        srcjx1 = (x + 1 < w) ? srcf[j][x + 1] : srcjx0;
        ldiff0 = ((srcx0 - srcjx0) >= 0 ? (srcx0 - srcjx0) : (-(srcx0 - srcjx0)));
        ldiff1 = ((srcx1 - srcjx1) >= 0 ? (srcx1 - srcjx1) : (-(srcx1 - srcjx1)));
        lsumdiff0 += ldiff0;
        lsumdiff1 += ldiff1;

        if (ldiff0 > thra || lsumdiff0 > thrb) {
            if (l0 == 0) l0 = -1;
        } else {
            l0++;
            sum0 += srcjx0;
        }

        if (ldiff1 > thra || lsumdiff1 > thrb) {
            if (l1 == 0) l1 = -1;
        } else {
            l1++;
            sum1 += srcjx1;
        }

        srcix0 = srcf[i][x];
        srcix1 = (x + 1 < w) ? srcf[i][x + 1] : srcix0;
        rdiff0 = ((srcx0 - srcix0) >= 0 ? (srcx0 - srcix0) : (-(srcx0 - srcix0)));
        rdiff1 = ((srcx1 - srcix1) >= 0 ? (srcx1 - srcix1) : (-(srcx1 - srcix1)));
        rsumdiff0 += rdiff0;
        rsumdiff1 += rdiff1;

        if (rdiff0 > thra || rsumdiff0 > thrb) {
            if (r0 == 0) r0 = -1;
        } else {
            r0++;
            sum0 += srcix0;
        }

        if (rdiff1 > thra || rsumdiff1 > thrb) {
            if (r1 == 0) r1 = -1;
        } else {
            r1++;
            sum1 += srcix1;
        }
    }

    const int count0 = (l0 < 0 ? 0 : l0) + (r0 < 0 ? 0 : r0) + 1;
    const int count1 = (l1 < 0 ? 0 : l1) + (r1 < 0 ? 0 : r1) + 1;

    dst[x] = (sum0 + (count0 >> 1)) / count0;
    if (x + 1 < w) {
        dst[x + 1] = (sum1 + (count1 >> 1)) / count1;
    }
}
}
