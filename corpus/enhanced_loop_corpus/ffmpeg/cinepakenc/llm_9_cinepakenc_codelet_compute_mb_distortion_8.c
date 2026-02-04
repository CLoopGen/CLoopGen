#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *a_data[4];
extern int a_linesize[4];
extern uint8_t *b_data[4];
extern int b_linesize[4];
extern int x;
extern int y;
extern int d;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increased trip count and expanded data access across multiple planes
    for (y = 0; y < 8; y += 2) {  // Double effective span, step by 2 for reduced iterations but larger reach
        for (x = 0; x < 8; x += 2) {
            int ay = y >> 1;  // Map back to original 4x4 range
            int ax = x >> 1;
            // Access two components per iteration to increase arithmetic density
            int d1 = a_data[0][(ax) + (ay) * a_linesize[0]] - b_data[0][(ax) + (ay) * b_linesize[0]];
            int d2 = a_data[1][(ax) + (ay) * a_linesize[1]] - b_data[1][(ax) + (ay) * b_linesize[1]];
            ret += d1 * d1 + d2 * d2 + d1 * d2; // More operations per loop: quadratic interaction term
        }
    }
}
