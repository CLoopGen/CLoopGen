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
for (i = 28; i >= 0; i -= 7) {
    if (i <= 24) {
        int ai = (int)((a >> i) & 255);
        int bi = (int)((b >> i) & 255);
        d = alpha_a * ai - alpha_b * bi;
        r += d * d;
    }
    alpha_a = (a >> 28) ^ 1;
    alpha_b = (b >> 28) ^ 1;
}
}
