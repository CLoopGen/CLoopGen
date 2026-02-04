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
    unsigned int sum = srcx;
    int l = 0, r = 0;
    int srcjx, srcix;
    _Bool lactive = 1, ractive = 1;
    for (int j = mid - 1; j >= 0 && lactive; j--) {
        srcjx = srcf[j][x];
        unsigned int ldiff = (srcx >= srcjx) ? (srcx - srcjx) : (srcjx - srcx);
        lsumdiff += ldiff;
        if (ldiff > thra || lsumdiff > thrb) {
            lactive = 0;
        } else {
            l++;
            sum += srcjx;
        }
    }
    for (int i = mid + 1; i < size && ractive; i++) {
        srcix = srcf[i][x];
        unsigned int rdiff = (srcx >= srcix) ? (srcx - srcix) : (srcix - srcx);
        rsumdiff += rdiff;
        if (rdiff > thra || rsumdiff > thrb) {
            ractive = 0;
        } else {
            r++;
            sum += srcix;
        }
    }
    int total = r + l + 1;
    dst[x] = (sum + (total >> 1)) / total;
}
}
