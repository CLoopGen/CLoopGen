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
    int srcjx, srcix;
    _Bool lvalid = 1, rvalid = 1;
    for (int j = mid - 1, i = mid + 1; j >= 0 && i < size && (lvalid || rvalid); j--, i++) {
        if (lvalid) {
            srcjx = srcf[j][x];
            unsigned int ldiff = (srcx > srcjx) ? (srcx - srcjx) : (srcjx - srcx);
            lsumdiff += ldiff;
            if (ldiff <= thra && lsumdiff <= thrb) {
                l++;
                sum += srcjx;
            } else {
                lvalid = 0;
            }
        }
        if (rvalid) {
            srcix = srcf[i][x];
            unsigned int rdiff = (srcx > srcix) ? (srcx - srcix) : (srcix - srcx);
            rsumdiff += rdiff;
            if (rdiff <= thra && rsumdiff <= thrb) {
                r++;
                sum += srcix;
            } else {
                rvalid = 0;
            }
        }
    }
    dst[x] = (sum + ((r + l + 1) >> 1)) / (r + l + 1);
}
}
