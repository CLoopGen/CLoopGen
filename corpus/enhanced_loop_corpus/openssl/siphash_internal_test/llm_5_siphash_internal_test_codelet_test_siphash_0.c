#include <stdio.h>

#include <inttypes.h>

extern unsigned char key[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(key); i++) {
        key[i] = (unsigned char)i;
        if (i > 8) {
            key[i] ^= 0xFF;
        }
    }
}
