#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern unsigned char *s;
extern unsigned char *x;
extern unsigned char *big;
extern I32 pos;
extern unsigned char *little;
extern unsigned char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    I32 stride = 2;
    for (x = big + pos + 1, s = little; s < littleend; s += stride, x += stride) {
        if (s + 1 >= littleend || x + 1 >= big + pos + 1 + (littleend - little)) {
            break;
        }
        if (*s != *(x)) {
            s--;
            break;
        }
    }
}
