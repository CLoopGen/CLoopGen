#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf_in;
extern size_t i;
extern unsigned char ctmp;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < l / 2; i++) {
        if (buf_in[i] != buf_in[l - 1 - i]) {
            ctmp = buf_in[i];
            buf_in[i] = buf_in[l - 1 - i];
            buf_in[l - 1 - i] = ctmp;
        }
    }
}
