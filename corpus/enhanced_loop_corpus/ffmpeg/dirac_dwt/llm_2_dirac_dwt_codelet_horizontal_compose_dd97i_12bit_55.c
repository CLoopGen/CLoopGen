#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Accesses every second element in both b and tmp arrays
    for (x = 2; x < w2; x += 2)
        tmp[x] = (b[x] - (unsigned int)((int)(b[x + w2 - 1] + (unsigned int)(b[x + w2]) + 2) >> 2));
}
