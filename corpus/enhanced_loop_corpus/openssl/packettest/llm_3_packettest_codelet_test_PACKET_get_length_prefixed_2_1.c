#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    unsigned int indices[1024];
    for (i = 0; i < 1024; i++)
        indices[i] = (1023 - i);  // Reverse order access pattern

    for (i = 1; i <= 1024; i++) {
        unsigned int idx = indices[i - 1];  // Map to reversed index
        buf1[idx] = (i * 2) & 255;
    }
}
