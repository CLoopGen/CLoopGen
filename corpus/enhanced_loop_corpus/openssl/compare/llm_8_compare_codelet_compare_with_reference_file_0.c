#include <stdio.h>

#include <inttypes.h>

extern char buf1[8192];
extern char buf2[8192];
extern size_t i;
extern size_t line_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < line_len * 2; i += 2) {
        j = i % 8192;
        if (buf1[j] == '?') {
            buf2[j] = '?';
        }
        buf1[j] ^= 0x01;
        buf2[j] ^= 0x01;
    }
}
