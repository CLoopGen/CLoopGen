#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled comparison (2x unroll)
    // This increases the number of arithmetic operations per iteration and reduces loop trip count by ~half.
    for (x = big, s = little; s + 1 < littleend; ) {
        char diff1 = *s++ - *x++;
        char diff2 = *s++ - *x++;
        if (diff1 != 0 || diff2 != 0) {
            s -= (diff1 == 0) ? 1 : 2;
            break;
        }
    }
    // Handle leftover element if needed (tail handling)
    if (s < littleend && s == littleend - 1) {
        if (*s != *x) {
            s--;
        }
    }
}
