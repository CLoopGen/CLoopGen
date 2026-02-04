#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(cbuf); i += 2) {
        cbuf[i] = i & 255;
        if (i + 1 < sizeof(cbuf)) {
            cbuf[i + 1] = (i + 1) & 255;
        }
    }
}
