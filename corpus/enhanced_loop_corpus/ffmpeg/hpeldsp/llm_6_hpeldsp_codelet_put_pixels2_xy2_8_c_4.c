#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;
extern int a1;
extern int b1;
extern int a0;
extern int b0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    int temp_a1 = pixels[0];
    int temp_b1 = pixels[1];
    temp_a1 += temp_b1;
    temp_b1 += pixels[2];
    block[0] = (temp_a1 + a0) >> 2;
    block[1] = (temp_b1 + b0) >> 2;
    pixels += line_size;
    block += line_size;
    int temp_a0 = pixels[0];
    int temp_b0 = pixels[1] + 2;
    temp_a0 += temp_b0;
    temp_b0 += pixels[2];
    block[0] = (temp_a1 + temp_a0) >> 2;
    block[1] = (temp_b1 + temp_b0) >> 2;
    pixels += line_size;
    block += line_size;
    a0 = temp_a0;
    b0 = temp_b0;
}
}
