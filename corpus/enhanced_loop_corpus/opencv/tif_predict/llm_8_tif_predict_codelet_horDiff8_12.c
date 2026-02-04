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
    tmsize_t j;
    for (i = stride - 8; i > 0; i -= 2) {
        cp[stride] = (unsigned char)((cp[stride] - cp[0] + cp[1] - cp[2]) & 255);
        cp[stride-1] = (unsigned char)((cp[stride-1] - cp[1] + cp[2] - cp[3]) & 255);
        cp -= 2;
    }
}
