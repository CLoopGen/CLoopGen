#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int b;
extern unsigned int ci;
extern unsigned int ri;
extern int color;
extern int x;
extern int y;
extern int ai;
extern int stride;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Prefetching Simulation
    // Increase stride-like behavior by accessing buf with a fixed offset pattern
    // Simulate wider strides by skipping elements (though within valid bounds)
    // Use a scaled index step to create artificial strided access across buf
    const int step = 7;  // Arbitrary prime step for strided effect
    int visited = 0;
    int total_elements = 12 * 6;
    int indices[72];
    
    // Generate strided index sequence over the logical iteration space
    for (int i = 0; i < total_elements; i++) {
        indices[i] = (i * step) % total_elements;
    }

    for (int i = 0; i < total_elements; i++) {
        int linear_idx = indices[i];
        y = linear_idx / 6;
        x = linear_idx % 6;

        if (!((data[4 + y] >> (5 - x)) & 1))
            color = data[0] & 15;
        else
            color = data[1] & 15;

        ai = ci + x + (stride * (ri + y));
        if (b)
            color ^= buf[ai];
        buf[ai] = color;
    }
}
