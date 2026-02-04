#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf_in;
extern size_t i;
extern unsigned char ctmp;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    size_t limit = l / 2;
    for (i = 0; i < limit; i += stride) {
        size_t j1 = i;
        size_t j2 = l - 1 - i;
        ctmp = buf_in[j1];
        buf_in[j1] = buf_in[j2];
        buf_in[j2] = ctmp;

        if (i + 1 < limit) {
            j1 = i + 1;
            j2 = l - 1 - (i + 1);
            ctmp = buf_in[j1];
            buf_in[j1] = buf_in[j2];
            buf_in[j2] = ctmp;
        }
    }
}
