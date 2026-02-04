#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern  uint8_t *f1;
extern  uint8_t *f2;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp1, temp2;
    for (int x = 0; x < w; x++) {
        temp1 = src[x] - f1[x];
        temp2 = src[x] - f2[x];
        temp1 = (temp1 >= 0) ? temp1 : -temp1;
        temp2 = (temp2 >= 0) ? temp2 : -temp2;
        dst[x] = temp2 > temp1 ? f2[x] : f1[x];
    }
}
