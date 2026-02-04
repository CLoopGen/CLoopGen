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
    int local_r = r;
    int local_alpha_a = alpha_a;
    int local_alpha_b = alpha_b;
    for (i = 24; i >= 0; i -= 8) {
        int shifted_a = (a >> i) & 255;
        int shifted_b = (b >> i) & 255;
        d = local_alpha_a * shifted_a - local_alpha_b * shifted_b;
        local_r += d * d;
        local_alpha_a = a >> 28;
        local_alpha_b = b >> 28;
    }
    r = local_r;
    alpha_a = local_alpha_a;
    alpha_b = local_alpha_b;
}
