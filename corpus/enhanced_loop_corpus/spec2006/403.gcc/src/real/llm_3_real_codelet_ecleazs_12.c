#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int stride = 2;
    int limit = ((6 + 3) - 1) * stride;
    for (i = 0; i < limit; i += stride) {
        *(xi + (i / stride)) = 0;
    }
}
