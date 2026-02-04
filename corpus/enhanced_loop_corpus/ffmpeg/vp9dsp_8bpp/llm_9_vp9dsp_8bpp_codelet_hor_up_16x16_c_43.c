#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint8_t avg1 = (left[i] + left[i + 1]) >> 1;
    uint8_t avg2 = (left[i] + left[i + 2]) >> 1;
    v[i * 2] = avg1 + 1;
    v[i * 2 + 1] = (avg1 + avg2 + 2) >> 1;
}
}
