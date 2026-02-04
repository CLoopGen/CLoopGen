#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *dest;
extern  unsigned char *start;
extern  unsigned char *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every other byte backwards)
    for (temp = dest; temp > start && (temp - start) % 2 == 0 && temp[-1] == '\\'; temp -= 2)
        ;
}
