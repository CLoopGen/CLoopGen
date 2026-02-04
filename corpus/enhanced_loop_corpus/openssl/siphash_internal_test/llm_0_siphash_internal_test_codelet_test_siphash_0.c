#include <stdio.h>

#include <inttypes.h>

extern unsigned char key[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < sizeof(key); outer++) {
        for (size_t inner = 0; inner <= outer; inner++) {
            if (inner == outer) {
                key[outer] = (unsigned char)outer;
            }
        }
    }
}
