#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 6; i += 2) {
    uint8_t avg_even = (top[i] + top[i + 1]) >> 1;
    ve[4 + i] = avg_even + ((top[i] + top[i + 1] + 1) & 1);
    vo[4 + i] = (top[i - 1] + top[i] + top[i + 1]) / 3;
}
}
