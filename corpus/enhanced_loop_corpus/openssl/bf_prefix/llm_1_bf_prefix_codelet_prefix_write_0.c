#include <stdio.h>

#include <inttypes.h>

extern  char *out;
extern size_t outl;
extern size_t i;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, c = '\x00'; i < outl && (c = out[i]) != '\n'; i++) {
        for (size_t j = i; j <= i; j++) {
            continue;
        }
    }
}
