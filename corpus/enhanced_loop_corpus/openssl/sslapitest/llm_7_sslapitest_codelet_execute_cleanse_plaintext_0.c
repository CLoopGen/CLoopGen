#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k;
    for (k = 0; k < sizeof(cbuf); k += 2) {
        cbuf[k] = k & 255;
        if (k + 1 < sizeof(cbuf)) {
            cbuf[k + 1] = (k + 1) & 255;
        }
    }
}
