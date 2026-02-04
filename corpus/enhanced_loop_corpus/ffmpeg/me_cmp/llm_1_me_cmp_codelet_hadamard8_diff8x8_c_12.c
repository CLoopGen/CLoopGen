#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) { // Reduce loop iterations but double work per iteration (effective depth decreased in logic coverage per step)
        int base_i1 = 8 * i;
        int base_i2 = 8 * (i + 4);
        int src_base1 = stride * i;
        int src_base2 = stride * (i + 4);

        // First half: i
        temp[base_i1 + 0] = (src[src_base1 + 0] - dst[src_base1 + 0]) + (src[src_base1 + 1] - dst[src_base1 + 1]);
        temp[base_i1 + 1] = (src[src_base1 + 0] - dst[src_base1 + 0]) - (src[src_base1 + 1] - dst[src_base1 + 1]);
        temp[base_i1 + 2] = (src[src_base1 + 2] - dst[src_base1 + 2]) + (src[src_base1 + 3] - dst[src_base1 + 3]);
        temp[base_i1 + 3] = (src[src_base1 + 2] - dst[src_base1 + 2]) - (src[src_base1 + 3] - dst[src_base1 + 3]);
        temp[base_i1 + 4] = (src[src_base1 + 4] - dst[src_base1 + 4]) + (src[src_base1 + 5] - dst[src_base1 + 5]);
        temp[base_i1 + 5] = (src[src_base1 + 4] - dst[src_base1 + 4]) - (src[src_base1 + 5] - dst[src_base1 + 5]);
        temp[base_i1 + 6] = (src[src_base1 + 6] - dst[src_base1 + 6]) + (src[src_base1 + 7] - dst[src_base1 + 7]);
        temp[base_i1 + 7] = (src[src_base1 + 6] - dst[src_base1 + 6]) - (src[src_base1 + 7] - dst[src_base1 + 7]);

        // Second half: i+4
        temp[base_i2 + 0] = (src[src_base2 + 0] - dst[src_base2 + 0]) + (src[src_base2 + 1] - dst[src_base2 + 1]);
        temp[base_i2 + 1] = (src[src_base2 + 0] - dst[src_base2 + 0]) - (src[src_base2 + 1] - dst[src_base2 + 1]);
        temp[base_i2 + 2] = (src[src_base2 + 2] - dst[src_base2 + 2]) + (src[src_base2 + 3] - dst[src_base2 + 3]);
        temp[base_i2 + 3] = (src[src_base2 + 2] - dst[src_base2 + 2]) - (src[src_base2 + 3] - dst[src_base2 + 3]);
        temp[base_i2 + 4] = (src[src_base2 + 4] - dst[src_base2 + 4]) + (src[src_base2 + 5] - dst[src_base2 + 5]);
        temp[base_i2 + 5] = (src[src_base2 + 4] - dst[src_base2 + 4]) - (src[src_base2 + 5] - dst[src_base2 + 5]);
        temp[base_i2 + 6] = (src[src_base2 + 6] - dst[src_base2 + 6]) + (src[src_base2 + 7] - dst[src_base2 + 7]);
        temp[base_i2 + 7] = (src[src_base2 + 6] - dst[src_base2 + 6]) - (src[src_base2 + 7] - dst[src_base2 + 7]);

        // Transformations for first block
        {
            int a, b;
            a = temp[base_i1 + 0]; b = temp[base_i1 + 2]; temp[base_i1 + 0] = a + b; temp[base_i1 + 2] = a - b;
            a = temp[base_i1 + 1]; b = temp[base_i1 + 3]; temp[base_i1 + 1] = a + b; temp[base_i1 + 3] = a - b;
            a = temp[base_i1 + 4]; b = temp[base_i1 + 6]; temp[base_i1 + 4] = a + b; temp[base_i1 + 6] = a - b;
            a = temp[base_i1 + 5]; b = temp[base_i1 + 7]; temp[base_i1 + 5] = a + b; temp[base_i1 + 7] = a - b;
            a = temp[base_i1 + 0]; b = temp[base_i1 + 4]; temp[base_i1 + 0] = a + b; temp[base_i1 + 4] = a - b;
            a = temp[base_i1 + 1]; b = temp[base_i1 + 5]; temp[base_i1 + 1] = a + b; temp[base_i1 + 5] = a - b;
            a = temp[base_i1 + 2]; b = temp[base_i1 + 6]; temp[base_i1 + 2] = a + b; temp[base_i1 + 6] = a - b;
            a = temp[base_i1 + 3]; b = temp[base_i1 + 7]; temp[base_i1 + 3] = a + b; temp[base_i1 + 7] = a - b;
        }

        // Transformations for second block
        {
            int a, b;
            a = temp[base_i2 + 0]; b = temp[base_i2 + 2]; temp[base_i2 + 0] = a + b; temp[base_i2 + 2] = a - b;
            a = temp[base_i2 + 1]; b = temp[base_i2 + 3]; temp[base_i2 + 1] = a + b; temp[base_i2 + 3] = a - b;
            a = temp[base_i2 + 4]; b = temp[base_i2 + 6]; temp[base_i2 + 4] = a + b; temp[base_i2 + 6] = a - b;
            a = temp[base_i2 + 5]; b = temp[base_i2 + 7]; temp[base_i2 + 5] = a + b; temp[base_i2 + 7] = a - b;
            a = temp[base_i2 + 0]; b = temp[base_i2 + 4]; temp[base_i2 + 0] = a + b; temp[base_i2 + 4] = a - b;
            a = temp[base_i2 + 1]; b = temp[base_i2 + 5]; temp[base_i2 + 1] = a + b; temp[base_i2 + 5] = a - b;
            a = temp[base_i2 + 2]; b = temp[base_i2 + 6]; temp[base_i2 + 2] = a + b; temp[base_i2 + 6] = a - b;
            a = temp[base_i2 + 3]; b = temp[base_i2 + 7]; temp[base_i2 + 3] = a + b; temp[base_i2 + 7] = a - b;
        }
    }
}
