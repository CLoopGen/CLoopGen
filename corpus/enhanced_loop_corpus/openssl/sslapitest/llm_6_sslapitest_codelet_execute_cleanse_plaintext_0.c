#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern unsigned char cbuf[16000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < sizeof(cbuf); j++) {
        cbuf[j] = (j + cbuf[(j > 0) ? j - 1 : 0]) & 255;
    }
}
