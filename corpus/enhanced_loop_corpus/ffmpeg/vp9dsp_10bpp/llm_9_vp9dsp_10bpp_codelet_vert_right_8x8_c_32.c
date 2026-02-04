#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[11];
extern uint16_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int idx = 8 / 2 + i * 2;
    if (idx < 11 && idx + 1 < 11) {
        ve[idx] = (top[2*i] + top[2*i + 1] + 1) >> 1;
        vo[idx] = (top[2*i - 1] + (top[2*i] << 1) + top[2*i + 1] + 2) >> 2;
        if (idx + 1 < 11 && 2*i + 2 < 11) {
            ve[idx + 1] = (top[2*i + 1] + top[2*i + 2] + 1) >> 1;
            vo[idx + 1] = (top[2*i] + (top[2*i + 1] << 1) + top[2*i + 2] + 2) >> 2;
        }
    }
}
}
