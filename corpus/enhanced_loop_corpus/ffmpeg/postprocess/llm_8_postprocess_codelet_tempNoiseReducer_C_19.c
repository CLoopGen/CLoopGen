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
for (y = 0; y < 16; y++) {
    int x;
    for (x = 0; x < 4; x++) {
        int ref = tempBlurred[x + y * stride];
        int cur = src[x + y * stride];
        int d1 = ref - cur;
        d += d1 * d1;
        d += d1 * d1; // Double the arithmetic operation per iteration
    }
}
}
