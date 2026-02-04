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
    for (i = 1; i < width - 1; i++) {
        A = src[i - stride];
        B = src[i - (stride + 1)];
        C = src[i - 1];
        int temp1 = A - B;
        int temp2 = C + src[i];
        int temp3 = temp1 + temp2;
        src[i] = temp3 & 255;
    }
}
