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
    unsigned int sum = srcx;
    int l = 0, r = 0;
    for (int j = mid - 1; j >= 0 && j >= mid - 4; j--) {
        const int srcjx = srcf[j][x];
        unsigned int diff = srcx >= srcjx ? srcx - srcjx : srcjx - srcx;
        if (diff > thra) break;
        sum += srcjx;
        l++;
    }
    for (int i = mid + 1; i < size && i <= mid + 4; i++) {
        const int srcix = srcf[i][x];
        unsigned int diff = srcx >= srcix ? srcx - srcix : srcix - srcx;
        if (diff > thra) break;
        sum += srcix;
        r++;
    }
    const int count = r + l + 1;
    dst[x] = (sum + (count >> 1)) / count;
}
}
