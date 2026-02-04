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



void loop() {
    // Variant 2: Reverse consecutive access with pointer arithmetic
    uint8_t *s1 = src1 + ((w - 1) >> 1);
    uint8_t *s2 = src2 + ((w - 1) >> 1);
    uint8_t *d1 = dst1 + ((w - 1) >> 1);
    uint8_t *d2 = dst2 + ((w - 1) >> 1);

    for (i = (w - 1) >> 1; i >= 0; i--) {
        a = *s1--;
        b = *s2--;
        *d1-- = (3 * a + b + 2) >> 2;
        *d2-- = (a + 3 * b + 2) >> 2;
    }
}
