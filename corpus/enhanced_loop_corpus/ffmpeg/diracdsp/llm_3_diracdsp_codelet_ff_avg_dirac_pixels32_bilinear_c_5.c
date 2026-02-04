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



void loop() {
    // Variant 2: Consecutive reverse-order traversal with local accumulation
    uint8_t temp_s0, temp_s1, temp_s2, temp_s3;
    for (x = 31; x >= 0; x--) {
        temp_s0 = s0[x];
        temp_s1 = s1[x];
        temp_s2 = s2[x];
        temp_s3 = s3[x];
        dst[x] = ((dst[x] + ((temp_s0 * w[0] + temp_s1 * w[1] + 
                      temp_s2 * w[2] + temp_s3 * w[3] + 8) >> 4) + 1) >> 1);
    }
}
