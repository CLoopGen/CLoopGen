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
    tmsize_t offset = stride - 4;
    for (i = 0; i < offset; i++) {
        cp[stride] = (unsigned char)((cp[stride] - cp[1]) & 255);
        cp++;
    }
}
