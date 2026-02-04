#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern unsigned long r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bits = 0; r > 0; ++bits) {
        if ((r & 1) == 0) {
            r >>= 1;
        } else {
            r >>= 1;
        }
    }
}
