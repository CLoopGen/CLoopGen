#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(cbuf); i++) {
        cbuf[i] = (i % 3 == 0) ? (i & 255) : 0;
    }
}
