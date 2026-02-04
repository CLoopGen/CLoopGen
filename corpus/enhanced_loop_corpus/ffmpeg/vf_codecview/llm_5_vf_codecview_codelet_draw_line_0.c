#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int ex;
extern int stride;
extern int color;
extern int x;
extern int y;
extern int fr;
extern int f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x <= ex; x++) {
    y = (x * f) >> 16;
    fr = (x * f) & 65535;
    int base_index = y * stride + x;
    int next_index = (y + 1) * stride + x;
    
    buf[base_index] += (color * (65536 - fr)) >> 16;
    
    if (fr > 32768)
        buf[next_index] += (color * (fr >> 1)) >> 16;
    else if (fr > 0)
        buf[next_index] += (color * fr) >> 17;
}
}
