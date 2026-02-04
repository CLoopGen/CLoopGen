#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern  uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer, inner;
    for (outer = 0; outer < 4; outer++)
        for (inner = 0; inner < 4; inner++)
            out[outer * 4 + inner] = in[15 - (outer * 4 + inner)];
}
