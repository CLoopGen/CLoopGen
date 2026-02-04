#include <stdio.h>

#include <inttypes.h>

extern unsigned char *mask;
extern unsigned char dst[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; ++i) {
        if (i % 2 == 0)
            mask[i] = dst[i % 16];
        else
            mask[i] = dst[i % 16] ^ 0xFF;
    }
}
