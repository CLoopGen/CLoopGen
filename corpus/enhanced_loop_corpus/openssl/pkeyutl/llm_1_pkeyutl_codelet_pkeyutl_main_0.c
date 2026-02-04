#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf_in;
extern size_t i;
extern unsigned char ctmp;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < (l / 2 + 3) / 4; j++) {
        size_t idx1 = j;
        size_t idx2 = l / 2 - 1 - j;

        if (idx1 < l / 2) {
            ctmp = buf_in[idx1];
            buf_in[idx1] = buf_in[l - 1 - idx1];
            buf_in[l - 1 - idx1] = ctmp;
        }

        if (idx2 < l / 2 && idx2 != idx1 && idx2 > idx1) {
            ctmp = buf_in[idx2];
            buf_in[idx2] = buf_in[l - 1 - idx2];
            buf_in[l - 1 - idx2] = ctmp;
        }
    }
}
