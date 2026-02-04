#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint8_t *in;
extern uint8_t *out;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < w; j++, out += 3, in -= 3) {
    int32_t v = ((((const uint8_t *)(in))[0] << 16) | (((const uint8_t *)(in))[1] << 8) | ((const uint8_t *)(in))[2]);
    ((uint8_t *)(out))[0] = (v >> 16);
    ((uint8_t *)(out))[1] = (v >> 8);
    ((uint8_t *)(out))[2] = v;
}
}
