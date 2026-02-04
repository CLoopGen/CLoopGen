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
    for (x = 0; x < 16; x++) {
        int sum = 0;
        sum += s0[x % 8] * w[0];
        sum += s1[x % 8] * w[1];
        sum += s2[x % 8] * w[2];
        sum += s3[x % 8] * w[3];
        sum += 16;
        dst[x] = (sum >> 5);
    }
}
