#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern uint8_t *iv;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via arithmetic)
    int indices[8] = {7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    for (i = 0; i < 8; i++)
        dst[i] = src[indices[i]] ^ iv[indices[i]];
}
