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
    for (j = stride - 4; j > 0; j--) {
        unsigned char temp = cp[0];
        cp[stride] = (unsigned char)((cp[stride] - temp) & 255);
        cp--;
    }
}
