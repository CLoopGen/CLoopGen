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
for (i = 2; i < 8 - 1; i++) {
    int sum_even = top[i] + top[i + 1];
    int sum_odd = top[i - 1] + (top[i] << 1) + top[i + 1];
    ve[4 + i] = (sum_even + 1) >> 1;
    vo[4 + i] = (sum_odd + 2) >> 2;
}
}
