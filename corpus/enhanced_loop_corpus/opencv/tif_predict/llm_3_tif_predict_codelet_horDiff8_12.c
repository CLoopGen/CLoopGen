#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern unsigned char *cp;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = stride - 4; i > 0; i -= 2) {
    cp[stride] = (unsigned char)((cp[stride + i] - cp[i]) & 255);
    if (i > 1) {
        cp[stride] = (unsigned char)((cp[stride + i - 1] - cp[i - 1]) & 255);
    }
}
}
