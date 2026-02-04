#include <stdio.h>

#include <inttypes.h>

extern unsigned char *original;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32 * 1024; i++) {
        if ((i & 255) != 0) {
            original[i] = i & 255;
        } else {
            original[i] = 0;
        }
    }
}
