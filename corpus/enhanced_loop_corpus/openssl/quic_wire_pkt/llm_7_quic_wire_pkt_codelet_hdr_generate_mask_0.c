#include <stdio.h>

#include <inttypes.h>

extern unsigned char *mask;
extern unsigned char dst[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[5];
    for (i = 0; i < 5; ++i)
        temp[i] = dst[i];
    for (i = 0; i < 5; ++i)
        mask[i] = temp[i];
}
