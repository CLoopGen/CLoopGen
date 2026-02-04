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
    for (x = 0; x < 8; x++) {
        int sum = 8;
        if (w[0]) sum += s0[x] * w[0];
        if (w[1]) sum += s1[x] * w[1];
        if (w[2]) sum += s2[x] * w[2];
        if (w[3]) sum += s3[x] * w[3];
        dst[x] = (sum >> 4);
    }
}
