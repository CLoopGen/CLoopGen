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
    tmsize_t temp_stride = stride;
    for (i = temp_stride - 4; i > 0; i--) {
        if ((cp[0] & 1) == 0) {
            cp[temp_stride] = (unsigned char)((cp[temp_stride] - cp[0]) & 255);
        }
        cp--;
    }
}
