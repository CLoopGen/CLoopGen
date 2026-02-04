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
int local_a0 = a0;
int local_b0 = b0;
for (i = 0; i < h; i += 2) {
    int current_a1 = pixels[0];
    int current_b1 = pixels[1];
    current_a1 += current_b1;
    current_b1 += pixels[2];
    block[0] = (current_a1 + local_a0) >> 2;
    block[1] = (current_b1 + local_b0) >> 2;
    pixels += line_size;
    block += line_size;
    int next_a0 = pixels[0];
    int next_b0 = pixels[1] + 2;
    next_a0 += next_b0;
    next_b0 += pixels[2];
    block[0] = (current_a1 + next_a0) >> 2;
    block[1] = (current_b1 + next_b0) >> 2;
    pixels += line_size;
    block += line_size;
    local_a0 = next_a0;
    local_b0 = next_b0;
}
a0 = local_a0;
b0 = local_b0;
}
