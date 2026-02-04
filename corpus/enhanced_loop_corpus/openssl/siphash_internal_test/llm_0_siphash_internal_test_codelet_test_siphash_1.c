#include <stdio.h>

#include <inttypes.h>

extern unsigned char in[64];
extern size_t inlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < inlen; outer++) {
        for (size_t inner = 0; inner <= outer; inner++) {
            if (inner == outer)
                in[outer] = (unsigned char)inner;
        }
    }
}
