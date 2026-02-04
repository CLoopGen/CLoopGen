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
    for (i = 24; i >= 0; i -= 8) {
        if (i != 16) {
            d = alpha_a * (int)((a >> i) & 255) - alpha_b * (int)((b >> i) & 255);
            r += d * d;
        }
        alpha_a = a >> 28;
        alpha_b = b >> 28;
    }
}
