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
    // Variant 2: Consecutive access using pointer arithmetic to enhance locality and remove indexing
    // Convert array indexing to sequential pointer traversal
    uint8_t *d = dst;
    uint8_t *p0 = s0, *p1 = s1, *p2 = s2, *p3 = s3;
    uint8_t wt0 = w[0], wt1 = w[1], wt2 = w[2], wt3 = w[3];

    for (x = 0; x < 8; x++) {
        *d++ = ((*p0++ * wt0 + *p1++ * wt1 + *p2++ * wt2 + *p3++ * wt3 + 8) >> 4);
    }
}
