#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *tempBlurred;
extern int y;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int idx = 0; idx < 64; ++idx) {
    int y = idx / 8;
    int x = idx % 8;
    int ref = tempBlurred[x + y * stride];
    int cur = src[x + y * stride];
    int d1 = ref - cur;
    d += d1 * d1;
}
}
