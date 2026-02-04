#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *dst;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (!(i & 1)) {
            dst[i] = 0;
        } else {
            dst[i] = 0;
        }
    }
}
