#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && (s[i] & 1) && (s[i] >> 2) > 0; i++)
        ;  // Increased arithmetic operations per iteration: bitwise and shift operations modify condition complexity
}
