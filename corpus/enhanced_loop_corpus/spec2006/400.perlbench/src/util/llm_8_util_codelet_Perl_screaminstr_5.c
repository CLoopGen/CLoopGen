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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled comparison (2x unroll)
    x = big + pos + 1;
    s = little;
    I32 step = 0;
    for (; s + 1 < littleend; s += 2, x += 2, step++) {
        if (*s != *x || *(s+1) != *(x+1)) {
            if (*s != *x) {
                s = s;
            } else {
                s = s + 1;
            }
            break;
        }
    }
    // Handle remaining element if needed
    for (; s < littleend && !(step > 0);) {
        if (*s++ != *x++) {
            s--;
            break;
        }
    }
}
