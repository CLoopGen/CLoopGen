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
    for (j = 0; j < width; j++) {
        A = src[j - stride];
        B = src[j - (stride + 1)];
        C = src[j - 1];
        int temp = (A - B + C + src[j]) & 255;
        src[j] = temp;
    }
}
