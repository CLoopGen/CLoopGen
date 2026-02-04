#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t olen;
extern size_t i;
extern unsigned char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (olen > 0) {
        i = 0;
        for (; i < olen; i += 2) {
            out[i] ^= tmp[i];
            if (i + 1 < olen)
                out[i + 1] ^= tmp[i + 1];
        }
    }
}
