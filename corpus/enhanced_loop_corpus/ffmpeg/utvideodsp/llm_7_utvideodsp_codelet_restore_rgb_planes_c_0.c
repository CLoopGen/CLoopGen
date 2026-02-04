#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_r;
extern uint8_t *src_g;
extern uint8_t *src_b;
extern ptrdiff_t linesize_r;
extern ptrdiff_t linesize_g;
extern ptrdiff_t linesize_b;
extern int width;
extern int height;
extern uint8_t r;
extern uint8_t g;
extern uint8_t b;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < height; j++) {
        // Eliminate intra-loop data dependency on 'g' by fusing computation and removing intermediate storage
        for (i = 0; i < width; i++) {
            // Directly compute using source values without assigning to scalar temporaries r, g, b
            // This removes RAW dependencies on r, g, b and introduces more direct memory access
            uint8_t g_val = src_g[i];
            src_r[i] = src_r[i] + g_val - 128;
            src_b[i] = src_b[i] + g_val - 128;
        }
        src_r += linesize_r;
        src_g += linesize_g;
        src_b += linesize_b;
    }
}
