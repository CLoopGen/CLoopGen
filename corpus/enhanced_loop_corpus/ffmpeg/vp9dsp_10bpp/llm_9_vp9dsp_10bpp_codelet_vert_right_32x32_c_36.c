#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[47];
extern uint16_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 48; i += 3) {
    ve[i / 3] = (top[i] + top[i + 1] + top[(i + 2) % 48] + 2) / 3;
    vo[i / 3] = (top[i] * 3 + top[(i + 1) % 48] * 2 + top[(i + 2) % 48] + 3) / 6;
    ve[i / 3 + 16] = (top[i] * 2 + top[(i + 1) % 48] + 2) / 3;
    vo[i / 3 + 16] = (top[(i + 1) % 48] + top[(i + 2) % 48] * 2 + 1) >> 1;
}
}
