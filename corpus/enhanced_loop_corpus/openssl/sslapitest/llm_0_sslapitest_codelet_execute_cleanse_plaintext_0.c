#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < sizeof(cbuf) / 256; outer++) {
        for (size_t inner = 0; inner < 256; inner++) {
            size_t i = outer * 256 + inner;
            cbuf[i] = i & 255;
        }
    }
}
