#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char s[256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[256];
    for (k = 0; k < 256; k++) {
        indices[k] = 255 - k; // reverse access pattern
    }
    for (k = 0; k < 256; k++) {
        s[indices[k]] = indices[k];
    }
}
