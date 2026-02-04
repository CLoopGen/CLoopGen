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
    uint8_t temp_a, temp_b;
    for (i = (w - 1) >> 1; i >= 0; i--) {
        temp_a = src1[i];
        temp_b = src2[i];
        dst1[i] = (3 * temp_a + temp_b + 2) >> 2;
        dst2[i] = (temp_a + 3 * temp_b + 2) >> 2;
    }
}
