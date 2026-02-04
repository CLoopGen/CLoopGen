#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf_in;
extern size_t i;
extern unsigned char ctmp;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 4;
    size_t limit = (l / 2) / stride * stride;
    for (i = 0; i < limit; i += stride) {
        ctmp = buf_in[i];
        buf_in[i] = buf_in[l - 1 - i];
        buf_in[l - 1 - i] = ctmp;

        ctmp = buf_in[i + 1];
        buf_in[i + 1] = buf_in[l - 2 - i];
        buf_in[l - 2 - i] = ctmp;

        ctmp = buf_in[i + 2];
        buf_in[i + 2] = buf_in[l - 3 - i];
        buf_in[l - 3 - i] = ctmp;

        ctmp = buf_in[i + 3];
        buf_in[i + 3] = buf_in[l - 4 - i];
        buf_in[l - 4 - i] = ctmp;
    }
    for (; i < l / 2; i++) {
        ctmp = buf_in[i];
        buf_in[i] = buf_in[l - 1 - i];
        buf_in[l - 1 - i] = ctmp;
    }
}
