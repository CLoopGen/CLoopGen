#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h + 8; y++) {
    for (x = 0; x < 8; x++) {
        int sum = 0;
        for (int k = 0; k < 5; k++) {
            int f_idx = 2 - k;
            int s_idx = x + (k - 2);
            sum += filter[k] * src[s_idx];
        }
        sum = (sum + 64) >> 7;
        tmp[x] = cm[sum];
    }
    tmp += 8;
    src += srcstride;
}
}
