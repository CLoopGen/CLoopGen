#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp;
extern int half;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_half;
    for (half = len2; tmp > 1; ) {
        next_half = half << 1;
        tmp >>= 1;
        half = next_half;
    }
}
