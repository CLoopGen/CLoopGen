#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t ve[47];
extern uint16_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int j = i * 4;
    vo[j + 0] = (left[j * 2 + 3] + (left[j * 2 + 2] << 1) + left[j * 2 + 1] + 2) >> 2;
    ve[j + 0] = (left[j * 2 + 4] + (left[j * 2 + 3] << 1) + left[j * 2 + 2] + 2) >> 2;
    vo[j + 1] = (left[j * 2 + 5] + (left[j * 2 + 4] << 1) + left[j * 2 + 3] + 2) >> 2;
    ve[j + 1] = (left[j * 2 + 6] + (left[j * 2 + 5] << 1) + left[j * 2 + 4] + 2) >> 2;
    vo[j + 2] = (left[j * 2 + 7] + (left[j * 2 + 6] << 1) + left[j * 2 + 5] + 2) >> 2;
    ve[j + 2] = (left[j * 2 + 8] + (left[j * 2 + 7] << 1) + left[j * 2 + 6] + 2) >> 2;
    vo[j + 3] = (left[j * 2 + 9] + (left[j * 2 + 8] << 1) + left[j * 2 + 7] + 2) >> 2;
    ve[j + 3] = (left[j * 2 +10] + (left[j * 2 + 9] << 1) + left[j * 2 + 8] + 2) >> 2;
}
}
