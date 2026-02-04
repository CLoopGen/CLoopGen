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
    for (x = 7; x >= 0; x--) {
        uint16_t sum = (uint16_t)(s0[x]) * w[0] + 
                       (uint16_t)(s1[x]) * w[1] + 
                       (uint16_t)(s2[x]) * w[2] + 
                       (uint16_t)(s3[x]) * w[3] + 
                       17;
        dst[x] = ((dst[x] + (sum >> 5)) + 1) >> 1;
    }
}
