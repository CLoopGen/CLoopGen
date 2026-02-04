#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t a;
extern uint32_t b;
extern int r;
extern int d;
extern int i;
extern int alpha_a;
extern int alpha_b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 24; i >= 0; i -= 4) {
    int shift_val1 = (a >> i) & 255;
    int shift_val2 = (b >> i) & 255;
    d = alpha_a * shift_val1 - alpha_b * shift_val2;
    r += d * d;
    alpha_a = (a >> 28) + (i % 3);
    alpha_b = (b >> 28) - (i % 2);
}
}
