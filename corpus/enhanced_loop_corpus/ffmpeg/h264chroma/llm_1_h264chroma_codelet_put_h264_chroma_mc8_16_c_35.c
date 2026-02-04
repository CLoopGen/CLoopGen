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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int offset = i * stride;
    for (int j = 0; j < 8; j++) {
        dst[offset + j] = (((A * src[offset + j]) + 32) >> 6);
    }
}
}
