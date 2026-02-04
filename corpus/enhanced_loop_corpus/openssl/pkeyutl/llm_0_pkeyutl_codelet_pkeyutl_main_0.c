#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf_in;
extern size_t i;
extern unsigned char ctmp;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer_i;
    for (outer_i = 0; outer_i < l / 4; outer_i++) {
        size_t inner_i;
        for (inner_i = 0; inner_i < 2; inner_i++) {
            size_t idx = outer_i * 2 + inner_i;
            if (idx >= l / 2) break;
            ctmp = buf_in[idx];
            buf_in[idx] = buf_in[l - 1 - idx];
            buf_in[l - 1 - idx] = ctmp;
        }
    }
}
