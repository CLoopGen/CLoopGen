#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n >= 16) return;
    for (size_t i = n; i < 16; ++i)
        ivec[i] = in[i];
}
