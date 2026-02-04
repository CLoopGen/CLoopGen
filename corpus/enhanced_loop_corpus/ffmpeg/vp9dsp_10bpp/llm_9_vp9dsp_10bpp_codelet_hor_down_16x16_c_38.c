#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[46];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 16 - 3; i++) {
    uint16_t l_avg1 = (left[i + 1] + left[i]) >> 1;
    uint16_t l_avg2 = (left[i + 2] + (left[i + 1] << 1) + left[i] + 2) >> 2;
    uint16_t t_avg = (top[i - 1] + (top[i] << 1) + top[i + 1] + 2) >> 2;
    v[i * 2] = l_avg1;
    v[i * 2 + 1] = l_avg2;
    v[16 * 2 + i] = t_avg;
}
}
