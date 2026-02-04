#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *d = dst;
    uint8_t *s = src;
    for (i = 0; i < h; i++) {
        for (int j = 0; j < 4; j++) {
            d[j] = (((d[j]) + ((((A * s[j] + E * s[step + j])) + 32) >> 6) + 1) >> 1);
        }
        d += stride;
        s += stride;
    }
}
