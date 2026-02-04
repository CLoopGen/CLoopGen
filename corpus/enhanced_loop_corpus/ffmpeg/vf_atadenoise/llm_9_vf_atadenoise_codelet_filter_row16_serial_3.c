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
    int j_start = mid - 1;
    int j_end = (mid - 4 >= 0) ? mid - 4 : 0;
    for (int j = j_start; j >= j_end; j--) {
        srcjx = srcf[j][x];
        unsigned int ldiff = (srcx >= srcjx) ? (srcx - srcjx) : (srcjx - srcx);
        lsumdiff += ldiff;
        if (ldiff > thra || lsumdiff > thrb) break;
        l++;
        sum += srcjx;
    }
    int i_start = mid + 1;
    int i_end = (mid + 5 < size) ? mid + 5 : size;
    for (int i = i_start; i < i_end; i++) {
        srcix = srcf[i][x];
        unsigned int rdiff = (srcx >= srcix) ? (srcx - srcix) : (srcix - srcx);
        rsumdiff += rdiff;
        if (rdiff > thra || rsumdiff > thrb) break;
        r++;
        sum += srcix;
    }
    int total_neighbors = r + l + 1;
    dst[x] = (sum + (total_neighbors >> 1)) / total_neighbors;
}
}
