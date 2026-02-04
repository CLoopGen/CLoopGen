#include <stdio.h>

#include <inttypes.h>

extern unsigned char key[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    size_t indices[sizeof(key)];
    for (size_t j = 0; j < sizeof(key); j++) {
        indices[j] = sizeof(key) - 1 - j; // reverse order access
    }
    for (size_t j = 0; j < sizeof(key); j++) {
        size_t i = indices[j];
        key[i] = (unsigned char)i;
    }
}
