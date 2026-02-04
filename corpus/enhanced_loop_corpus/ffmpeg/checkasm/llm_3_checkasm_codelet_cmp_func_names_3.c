#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  char *b;
extern int ascii_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every second element instead of each consecutive one
    size_t stride = 2;
    size_t i = 0;
    for (; !(ascii_diff = *(const unsigned char *)(a + i) - *(const unsigned char *)(b + i)) && *(a + i); i += stride)
        ;
    // Adjust global pointers a and b to reflect final position after strided traversal
    a += i;
    b += i;
}
