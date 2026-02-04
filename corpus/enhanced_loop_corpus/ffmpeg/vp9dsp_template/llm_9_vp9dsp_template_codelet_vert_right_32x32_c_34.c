#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[47];
extern uint8_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64 / 2 - 2; i += 2) {
    vo[i] = (left[i * 2 + 3] + left[i * 2 + 2] * 3 + left[i * 2 + 1] * 2 + left[i * 2 + 0] + 4) >> 3;
    ve[i] = (left[i * 2 + 4] + left[i * 2 + 3] * 3 + left[i * 2 + 2] * 2 + left[i * 2 + 1] + 4) >> 3;
    if (i + 1 < 32 / 2 - 2) {
        vo[i + 1] = (left[(i + 1) * 2 + 3] + left[(i + 1) * 2 + 2] * 2 + left[(i + 1) * 2 + 1] + 2) >> 2;
        ve[i + 1] = (left[(i + 1) * 2 + 4] + left[(i + 1) * 2 + 3] * 2 + left[(i + 1) * 2 + 2] + 2) >> 2;
    }
}
}
