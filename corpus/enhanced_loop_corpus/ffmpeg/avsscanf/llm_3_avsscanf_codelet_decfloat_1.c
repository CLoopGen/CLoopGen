#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal using an index derived from z
    for (int i = z - 1; i < 128 && !x[i]; i++)
        z = i + 1;
}
