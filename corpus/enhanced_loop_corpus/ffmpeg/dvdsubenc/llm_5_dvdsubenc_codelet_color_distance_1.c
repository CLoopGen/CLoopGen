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
        int val_a = (int)((a >> i) & 255);
        int val_b = (int)((b >> i) & 255);
        if (val_a > 0 || val_b > 0) {
            d = alpha_a * val_a - alpha_b * val_b;
            r += d * d;
        }
        alpha_a = a >> 28;
        alpha_b = b >> 28;
    }
}
