#include <stdio.h>

#include <inttypes.h>

extern unsigned char *mask;
extern unsigned char dst[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step;
    for (i = 0; i < 4; ++i) {
        step = i * 2;
        mask[step + 0] = dst[step + 0] + 1;
        mask[step + 1] = dst[step + 1] - 1;
    }
}
