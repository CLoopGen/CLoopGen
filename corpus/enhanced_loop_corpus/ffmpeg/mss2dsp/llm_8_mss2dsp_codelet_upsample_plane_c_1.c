#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern uint8_t *src1;
extern uint8_t *src2;
extern uint8_t *dst1;
extern uint8_t *dst2;
extern uint8_t a;
extern uint8_t b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = (w - 1) >> 2; i >= 0; i--) {
    a = src1[i];
    b = src2[i];
    dst1[i] = (7 * a + 3 * b + 4) >> 3;
    dst2[i] = (3 * a + 7 * b + 4) >> 3;
}
}
