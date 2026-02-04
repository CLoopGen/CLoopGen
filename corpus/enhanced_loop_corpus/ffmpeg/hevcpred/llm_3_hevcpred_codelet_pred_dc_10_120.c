#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern  uint16_t *top;
extern  uint16_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (access arrays from end to start)
    for (i = size - 1; i >= 0; i--)
        dc += left[i] + top[i];
}
