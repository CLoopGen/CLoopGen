#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern ptrdiff_t stride;
extern uint8_t *src;
extern uint8_t *left;
extern int bottom_left_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer_start = 32;
int outer_end = 32 + bottom_left_size;
int step = (bottom_left_size + 3) / 4; // Divide into up to 4 chunks
if (step == 0) step = 1;
for (int chunk = 0; chunk < 4 && outer_start + chunk * step < outer_end; chunk++) {
    int start = outer_start + chunk * step;
    int end = start + step;
    if (end > outer_end) end = outer_end;
    for (i = start; i < end; i++)
        left[i] = src[(-1) + stride * (i)];
}
}
