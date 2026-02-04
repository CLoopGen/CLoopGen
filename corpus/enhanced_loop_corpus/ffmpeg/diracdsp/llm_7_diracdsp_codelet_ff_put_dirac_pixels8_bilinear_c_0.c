#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int x;
extern  uint8_t *s0;
extern  uint8_t *s1;
extern  uint8_t *s2;
extern  uint8_t *s3;
extern  uint8_t *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t acc;
    for (x = 0; x < 8; x++) {
        acc = s0[x] * w[0];
        acc += s1[x] * w[1]; 
        acc += s2[x] * w[2]; 
        acc += s3[x] * w[3];
        dst[x] = (acc + 8) >> 4;
    }
}
