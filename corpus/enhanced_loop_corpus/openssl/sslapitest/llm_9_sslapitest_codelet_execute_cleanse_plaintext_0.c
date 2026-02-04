#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < sizeof(cbuf); i++) {
        cbuf[i] = 0;
        for (j = 0; j < 8; j++) {
            cbuf[i] ^= (i >> j) & 1;
        }
        cbuf[i] = (cbuf[i] << 4) | (cbuf[i] & 15);
    }
}
