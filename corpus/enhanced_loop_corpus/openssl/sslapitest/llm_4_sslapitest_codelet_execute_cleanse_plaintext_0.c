#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(cbuf); i++) {
        if ((i & 15) < 8) {
            cbuf[i] = i & 255;
        } else {
            cbuf[i] = 0;
        }
    }
}
