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
    _Bool l_active = 1, r_active = 1;
    for (int j = mid - 1; j >= 0 && l_active; j--) {
        srcjx = srcf[j][x];
        unsigned int ldiff = (srcx - srcjx) ^ ((srcx - srcjx) >> 31);
        lsumdiff += ldiff;
        l_active = (ldiff <= thra && lsumdiff <= thrb);
        if (l_active) {
            l++;
            sum += srcjx;
        }
    }
    for (int i = mid + 1; i < size && r_active; i++) {
        srcix = srcf[i][x];
        unsigned int rdiff = (srcix - srcx) ^ ((srcix - srcx) >> 31);
        rsumdiff += rdiff;
        r_active = (rdiff <= thra && rsumdiff <= thrb);
        if (r_active) {
            r++;
            sum += srcix;
        }
    }
    int total = r + l + 1;
    dst[x] = (sum + (total >> 1)) / total;
}
}
