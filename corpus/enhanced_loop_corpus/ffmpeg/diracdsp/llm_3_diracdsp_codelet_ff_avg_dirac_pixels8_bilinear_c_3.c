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
    // Variant 2: Consecutive Block Access using pointer arithmetic with local accumulation
    uint8_t *d = dst + 7;
    uint8_t *a = s0 + 7;
    uint8_t *b = s1 + 7;
    uint8_t *c = s2 + 7;
    uint8_t *e = s3 + 7;
    const uint8_t *wt = w;
    for (x = 0; x < 8; x++) {
        // Process from end to beginning, consecutive backward traversal
        int sum = (*a * wt[0] + *b * wt[1] + *c * wt[2] + *e * wt[3] + 8) >> 4;
        *d = ((*d + sum + 1) >> 1);
        d--; a--; b--; c--; e--;
    }
}
