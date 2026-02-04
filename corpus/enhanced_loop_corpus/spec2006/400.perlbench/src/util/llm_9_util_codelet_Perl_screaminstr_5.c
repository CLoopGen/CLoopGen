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
    // Variant 2: Reduced trip count by skipping every other byte, increasing stride
    x = big + pos + 1;
    s = little;
    for (; s + 1 < littleend; s += 2, x += 2) {
        if (*s != *x) {
            s = s;
            break;
        }
    }
    // Ensure minimal progress even in edge cases
    if (s == little && s < littleend) {
        if (*s++ != *x++) {
            s--;
        }
    }
}
