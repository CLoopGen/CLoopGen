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
    for (i = 0; i < width; i += 2) {
        A = src[i - stride];
        B = src[i - (stride + 1)];
        C = src[i - 1];
        src[i] = (A - B + C + src[i]) & 255;
        
        if (i + 1 < width) {
            int j = i + 1;
            A = src[j - stride];
            B = src[j - (stride + 1)];
            C = src[j - 1];
            src[j] = (A - B + C + src[j]) & 255;
        }
    }
}
