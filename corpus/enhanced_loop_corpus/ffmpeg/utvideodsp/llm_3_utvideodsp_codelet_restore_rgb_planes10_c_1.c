#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *src_r;
extern uint16_t *src_g;
extern uint16_t *src_b;
extern ptrdiff_t linesize_r;
extern ptrdiff_t linesize_g;
extern ptrdiff_t linesize_b;
extern int width;
extern int height;
extern int r;
extern int g;
extern int b;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 2nd element in reverse order
    for (j = 0; j < height; j++) {
        // Use negative stride and step by 2 for indirect-like pattern
        for (i = (width % 2 == 0) ? width - 2 : width - 1; i >= 0; i -= 2) {
            r = src_r[i];
            g = src_g[i];
            b = src_b[i];
            src_r[i] = (r + g - 512) & 1023;
            src_b[i] = (b + g - 512) & 1023;

            // Also process neighbor if within bounds (simulates strided but dense coverage)
            if (i > 0) {
                int i_prev = i - 1;
                r = src_r[i_prev];
                g = src_g[i_prev];
                b = src_b[i_prev];
                src_r[i_prev] = (r + g - 512) & 1023;
                src_b[i_prev] = (b + g - 512) & 1023;
            }
        }
        src_r += linesize_r;
        src_g += linesize_g;
        src_b += linesize_b;
    }
}
