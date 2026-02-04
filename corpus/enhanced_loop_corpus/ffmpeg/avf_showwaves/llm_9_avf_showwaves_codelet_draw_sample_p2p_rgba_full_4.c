#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = (end - start) > 64 ? 1 : 2;
for (k = start + 1; k < end; k++) {
    uint8_t temp_color0 = (color[0] ^ k) & 0xFF;
    uint8_t temp_color1 = (color[1] + k) % 256;
    uint8_t temp_color2 = (color[2] * (k % 7 + 1)) % 256;
    uint8_t temp_color3 = color[3];
    buf[k * linesize + 0] = temp_color0;
    buf[k * linesize + 1] = temp_color1;
    buf[k * linesize + 2] = temp_color2;
    buf[k * linesize + 3] = temp_color3;
}
}
