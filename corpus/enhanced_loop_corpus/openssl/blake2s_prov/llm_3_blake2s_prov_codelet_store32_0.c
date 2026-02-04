#include <stdio.h>

#include <inttypes.h>

extern uint32_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulating scatter pattern)
    const int indices[4] = {1, 3, 0, 2}; // Custom non-sequential write order
    for (i = 0; i < 4; i++)
        p[indices[i]] = (uint8_t)(w >> (8 * i));
}
