#include <stdio.h>

#include <inttypes.h>

extern  char *out;
extern size_t outl;
extern size_t i;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0, c = '\x00'; i < outl; i += 2) {
        c = out[i];
        if (c == '\n') break;
        if (i + 1 < outl && (c = out[i + 1]) == '\n') break;
    }
}
