#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp;
extern int half;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0, half = len2; i < 10 && tmp > 1; i++, half <<= 2, tmp >>= 2) {
        tmp = (tmp > 1) ? (tmp + (tmp >> 2)) : tmp;
    }
}
