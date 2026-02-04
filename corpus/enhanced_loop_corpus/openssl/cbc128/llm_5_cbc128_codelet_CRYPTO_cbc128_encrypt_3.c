#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = n; i < 16; ++i) {
        if (i >= 0)
            out[i] = iv[i];
    }
}
