#include <stdio.h>

#include <inttypes.h>

extern unsigned char key[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (size_t i = 0; i < sizeof(key); i += 2) {
        key[i] = (unsigned char)i;
        if (i + 1 < sizeof(key)) {
            key[i + 1] = (unsigned char)(i + 1);
        }
    }
}
