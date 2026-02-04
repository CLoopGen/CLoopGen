#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    unsigned int indices[16];
    for (unsigned int i = 0; i <= 15; i++) {
        indices[i] = 15 - i;  // Reverse order access: 15, 14, ..., 0
    }
    for (unsigned int i = 0; i <= 15; i++) {
        count[indices[i]] = 0;
    }
    len = 15;
}
