#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[23];
extern uint16_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < 16 - 1; i += 2) {
    uint16_t t0 = top[i-2], t1 = top[i-1], t2 = top[i], t3 = top[i+1];
    ve[8 + i/2] = (t1 + t2 + 1) >> 1;
    vo[8 + i/2] = (t0 + t1*3 + t2*3 + t3 + 4) >> 3;
}
}
