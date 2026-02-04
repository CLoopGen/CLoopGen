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
    const tmsize_t limit = stride;
    for (i = limit - 4; i > 0; i--) {
        unsigned char diff = (unsigned char)(cp[limit] - cp[0]);
        if (diff != 0) {
            cp[limit] = diff;
            cp--;
        } else {
            cp--;
            continue;
        }
    }
}
