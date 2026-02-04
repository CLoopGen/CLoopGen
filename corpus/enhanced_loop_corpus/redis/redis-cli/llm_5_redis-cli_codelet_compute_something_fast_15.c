#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char s[256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 256; k++) {
        if (k < 128) {
            s[k] = k;
        } else {
            s[k] = 0;
        }
    }
}
