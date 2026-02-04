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
    // This variant compares every second element in both arrays, effectively using a strided access pattern.
    char *local_big = big;
    char *local_little = little;
    for (x = local_big, s = local_little; s < littleend; x += 2, s += 2) {
        if (s + 1 >= littleend) break;
        if (*s != *x || *(s + 1) != *(x + 1)) {
            s--;
            break;
        }
    }
}
