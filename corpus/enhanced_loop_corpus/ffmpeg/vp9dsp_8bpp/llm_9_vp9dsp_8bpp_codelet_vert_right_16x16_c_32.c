#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[23];
extern uint8_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    vo[i]     = (left[i * 2 + 3] + (left[i * 2 + 2] << 1) + left[i * 2 + 1] + 2) >> 2;
    ve[i]     = (left[i * 2 + 4] + (left[i * 2 + 3] << 1) + left[i * 2 + 2] + 2) >> 2;
    if (i + 1 < 8) {
        vo[i+1] = (left[(i+1) * 2 + 3] + (left[(i+1) * 2 + 2] << 1) + left[(i+1) * 2 + 1] + 2) >> 2;
        ve[i+1] = (left[(i+1) * 2 + 4] + (left[(i+1) * 2 + 3] << 1) + left[(i+1) * 2 + 2] + 2) >> 2;
    }
}
}
