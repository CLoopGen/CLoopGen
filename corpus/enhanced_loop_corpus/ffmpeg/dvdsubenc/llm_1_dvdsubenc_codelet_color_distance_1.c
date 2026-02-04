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
        // Reduced effective loop depth by unrolling two iterations manually
        // First iteration (i = 24)
        d = alpha_a * (int)((a >> 24) & 255) - alpha_b * (int)((b >> 24) & 255);
        r += d * d;
        alpha_a = a >> 28;
        alpha_b = b >> 28;

        // Second iteration (i = 16)
        d = alpha_a * (int)((a >> 16) & 255) - alpha_b * (int)((b >> 16) & 255);
        r += d * d;
        alpha_a = a >> 28;
        alpha_b = b >> 28;

        // Third iteration (i = 8)
        d = alpha_a * (int)((a >> 8) & 255) - alpha_b * (int)((b >> 8) & 255);
        r += d * d;
        alpha_a = a >> 28;
        alpha_b = b >> 28;

        // Final iteration (i = 0)
        d = alpha_a * (int)((a >> 0) & 255) - alpha_b * (int)((b >> 0) & 255);
        r += d * d;
        alpha_a = a >> 28;
        alpha_b = b >> 28;

        break; // Ensures loop runs only once due to full unrolling
    }
}
