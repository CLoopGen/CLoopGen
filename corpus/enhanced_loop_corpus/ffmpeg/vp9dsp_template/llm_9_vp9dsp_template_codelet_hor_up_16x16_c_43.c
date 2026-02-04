#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16 - 1; i++) {
    uint8_t a = left[i];
    uint8_t b = left[i + 1];
    uint8_t avg1 = (a + b + 1) >> 1;
    uint8_t sum = a + (b << 1) + (i + 2 < 30 ? left[i + 2] : 0) + 2;
    uint8_t avg2 = sum >> 2;
    v[i * 2] = avg1;
    v[i * 2 + 1] = avg2;
}
}
