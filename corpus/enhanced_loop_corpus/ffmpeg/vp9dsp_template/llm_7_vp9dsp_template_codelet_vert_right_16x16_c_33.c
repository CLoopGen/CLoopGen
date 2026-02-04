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
    for (i = 0; i < 16 - 1; i++) {
        int idx = 16 / 2 + i;
        uint8_t t_val = (top[i] + top[i + 1] + 1) >> 1;
        ve[idx] = t_val;
        vo[idx] = (i == 0) ? 
                  (top[i] * 3 + top[i + 1] + 2) >> 2 : 
                  (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}
