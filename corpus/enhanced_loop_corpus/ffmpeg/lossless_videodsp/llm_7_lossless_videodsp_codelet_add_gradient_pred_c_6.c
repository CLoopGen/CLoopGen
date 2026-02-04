#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern  ptrdiff_t stride;
extern  ptrdiff_t width;
extern int A;
extern int B;
extern int C;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 1; j < width; j++) {
        A = src[j - stride];
        B = src[j - (stride + 1)];
        C = src[j - 1];
        src[j] = (A - B + C + src[j - 1]) & 255;
    }
    if (width > 0) {
        src[0] = (src[-stride] - src[-(stride + 1)] + src[-1] + src[0]) & 255;
    }
}
