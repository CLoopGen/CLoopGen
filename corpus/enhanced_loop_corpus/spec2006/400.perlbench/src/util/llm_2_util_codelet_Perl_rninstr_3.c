#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (x = big + 2, s = little; s < littleend; ) {
        if (*(x + 0) != *(s + 0)) {
            s--;
            break;
        }
        x += 2;
        s += 2;
        if (s >= littleend) break;
    }
}
