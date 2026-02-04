#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 4;
    for (i = 0; i < sizeof(cbuf); i += step) {
        for (size_t j = 0; j < step && (i + j) < sizeof(cbuf); j++) {
            cbuf[i + j] = (i + j) & 255;
        }
    }
}
