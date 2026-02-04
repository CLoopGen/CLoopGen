#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < sizeof(cbuf); i++) {
        for (size_t j = 0; j < 1; j++) { // Artificially nested single-iteration loop
            cbuf[i] = i & 255;
        }
    }
}
