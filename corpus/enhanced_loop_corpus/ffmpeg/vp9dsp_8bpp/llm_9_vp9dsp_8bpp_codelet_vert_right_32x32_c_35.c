#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[47];
extern uint8_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < 30; i += 2) {
    uint8_t temp_even = (top[i-1] + top[i] + 1) >> 1;
    uint8_t temp_odd = (top[i-2] + (top[i-1] << 1) + top[i] + 2) >> 2;
    ve[16 + (i >> 1)] = temp_even;
    vo[16 + (i >> 1)] = temp_odd;
    
    // Unrolled second iteration
    if (i + 1 < 30) {
        temp_even = (top[i] + top[i+1] + 1) >> 1;
        temp_odd = (top[i-1] + (top[i] << 1) + top[i+1] + 2) >> 2;
        ve[16 + ((i+1) >> 1)] = temp_even;
        vo[16 + ((i+1) >> 1)] = temp_odd;
    }
}
}
