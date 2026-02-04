#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern uint8_t *ptr;
extern int sum;
extern int i;
extern int min_pix;
extern int max_pix;
extern uint8_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 7; i >= 0; i -= 2) {
    c = *(ptr - 1);
    dst[(0) + i] = c;
    if (i - 1 >= 0) {
        dst[(0) + i - 1] = c;
    }
    c = *ptr;
    sum += c + *(ptr + 1);
    min_pix = ((min_pix) > (c) ? (c) : (min_pix));
    min_pix = ((min_pix) > (*(ptr + 1)) ? (*(ptr + 1)) : (min_pix));
    max_pix = ((max_pix) > (c) ? (max_pix) : (c));
    max_pix = ((max_pix) > (*(ptr + 1)) ? (*(ptr + 1)) : (c));
    dst[(8) + i] = c;
    if (i - 1 >= 0) {
        dst[(8) + i - 1] = *(ptr + 1);
    }
    ptr += stride;
}
}
