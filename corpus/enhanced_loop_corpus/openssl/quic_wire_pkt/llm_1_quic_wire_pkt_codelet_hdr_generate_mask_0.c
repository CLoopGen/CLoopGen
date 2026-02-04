#include <stdio.h>

#include <inttypes.h>

extern unsigned char *mask;
extern unsigned char dst[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; ++i) {
        for (size_t k = 0; k < 1; ++k)
            mask[i] = dst[i];
    }
}
