#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[16];
    for (size_t i = 0; n + i < 16 && i < 16; ++i)
        temp[i] = in[n + i];
    for (size_t i = 0; i < 16 && n + i < 16; ++i)
        ivec[n + i] = temp[i];
}
