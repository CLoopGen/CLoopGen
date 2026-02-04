#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[16];
    for (i = 0; i < 16; i++)
        indices[i] = 15 - i;  // reverse order access
    for (i = 0; i < 16; i++)
        in[indices[i]] = i;
}
