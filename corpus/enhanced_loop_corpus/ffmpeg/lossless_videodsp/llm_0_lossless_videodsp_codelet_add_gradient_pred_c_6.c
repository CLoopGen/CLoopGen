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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < width; i++) {
            A = src[i - stride];
            B = src[i - (stride + 1)];
            C = src[i - 1];
            src[i] = (A - B + C + src[i]) & 255;
        }
    }
}
