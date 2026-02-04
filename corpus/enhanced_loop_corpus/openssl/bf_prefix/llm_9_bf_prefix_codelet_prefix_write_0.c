#include <stdio.h>

#include <inttypes.h>

extern  char *out;
extern size_t outl;
extern size_t i;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0, c = '\x00'; i < outl && (c = out[i]) != '\n'; i += step) {
        c = out[i];
        step = (c % 2 == 0) ? 1 : 2;
    }
}
