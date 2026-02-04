#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf_in;
extern size_t i;
extern unsigned char ctmp;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < l / 2; i++) {
        j = l - 1 - i;
        ctmp = buf_in[i] ^ buf_in[j];
        buf_in[i] = buf_in[i] ^ ctmp;
        buf_in[j] = buf_in[j] ^ ctmp;
    }
}
