#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 4; y++) {
        for (int inner = 0; inner < 4; inner++) {
            const uint8_t *cm_in = cm + src[-1];
            int offset = inner * 4;
            src[0 + offset] = cm_in[top[0 + offset]];
            src[1 + offset] = cm_in[top[1 + offset]];
            src[2 + offset] = cm_in[top[2 + offset]];
            src[3 + offset] = cm_in[top[3 + offset]];
            src += stride;
            if (inner < 3) src -= stride; // Adjust pointer only after full row
        }
        src += 4 * stride - 16; // Move to next row group
    }
}
