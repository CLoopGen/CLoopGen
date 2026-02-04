#include <stdio.h>

#include <inttypes.h>

extern unsigned char *mask;
extern unsigned char dst[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; ++i) {
        if (!(i & 1)) // Only copy for even indices
            mask[i] = dst[i];
    }
}
