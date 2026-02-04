#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < h; i++) {
        j = i * stride;
        dst[j] = ((((A * src[j] + E * src[j + step])) + 32) >> 6);
    }
}
