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
    int temp_alpha_a = alpha_a;
    int temp_alpha_b = alpha_b;
    for (i = 24; i >= 0; i -= 8) {
        d = temp_alpha_a * (int)((a >> i) & 255) - temp_alpha_b * (int)((b >> i) & 255);
        r += d * d;
        temp_alpha_a = (a >> 28);
        temp_alpha_b = (b >> 28);
    }
    alpha_a = temp_alpha_a;
    alpha_b = temp_alpha_b;
}
