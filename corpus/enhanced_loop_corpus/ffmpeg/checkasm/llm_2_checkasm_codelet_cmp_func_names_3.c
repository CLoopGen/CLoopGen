#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  char *b;
extern int ascii_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing (treating a and b as arrays accessed consecutively)
    size_t i = 0;
    for (; !(ascii_diff = *(const unsigned char *)(a + i) - *(const unsigned char *)(b + i)) && *(a + i); i++, a++, b++)
        ;
}
