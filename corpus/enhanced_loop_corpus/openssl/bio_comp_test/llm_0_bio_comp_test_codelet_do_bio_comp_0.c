#include <stdio.h>

#include <inttypes.h>

extern unsigned char *original;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer, inner;
    for (outer = 0; outer < 32; outer++)
        for (inner = 0; inner < 1024; inner++)
            original[outer * 1024 + inner] = (outer * 1024 + inner) & 255;
}
