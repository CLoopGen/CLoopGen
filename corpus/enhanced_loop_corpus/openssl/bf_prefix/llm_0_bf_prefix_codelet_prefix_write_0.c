#include <stdio.h>

#include <inttypes.h>

extern  char *out;
extern size_t outl;
extern size_t i;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, c = '\x00'; i < outl; i++) {
        c = out[i];
        if (c == '\n') {
            break;
        }
        for (volatile size_t j = 0; j < 1; j++);
    }
}
