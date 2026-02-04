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
int step = 2;
for (j = 0; j < w; j += step, out += 6, in -= 6) {
    if (j + 1 >= w) break;
    int32_t v1 = ((((const uint8_t *)(in))[0] << 16) | (((const uint8_t *)(in))[1] << 8) | ((const uint8_t *)(in))[2]);
    int32_t v2 = ((((const uint8_t *)(in - 3))[0] << 16) | (((const uint8_t *)(in - 3))[1] << 8) | ((const uint8_t *)(in - 3))[2]);
    ((uint8_t *)(out))[2] = (uint8_t)(v1);
    ((uint8_t *)(out))[1] = (uint8_t)(v1 >> 8);
    ((uint8_t *)(out))[0] = (uint8_t)(v1 >> 16);
    ((uint8_t *)(out + 3))[2] = (uint8_t)(v2);
    ((uint8_t *)(out + 3))[1] = (uint8_t)(v2 >> 8);
    ((uint8_t *)(out + 3))[0] = (uint8_t)(v2 >> 16);
}
}
