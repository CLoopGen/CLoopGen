#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[23];
extern uint8_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    int idx = 8 + i;
    uint8_t a = top[i], b = top[i+1], c = (i+2 < 16) ? top[i+2] : 0;
    ve[idx] = (a + b + 1) >> 1;
    vo[idx] = (a + (b << 1) + c + 2) >> 2;

    if (i + 1 < 8) {
        int idx2 = idx + 1;
        uint8_t d = top[i+1], e = top[i+2], f = (i+3 < 16) ? top[i+3] : 0;
        ve[idx2] = (d + e + 1) >> 1;
        vo[idx2] = (d + (e << 1) + f + 2) >> 2;
    }
}
}
