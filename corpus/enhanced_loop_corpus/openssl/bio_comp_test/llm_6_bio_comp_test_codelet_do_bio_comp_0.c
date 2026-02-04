#include <stdio.h>

#include <inttypes.h>

extern unsigned char *original;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32 * 1024; i++) {
        unsigned char val = i & 255;
        original[i] = val;
        original[i + 16] = val; // Introduces WAW and WAR dependencies with future iterations
    }
}
