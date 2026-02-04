#include <stdio.h>

#include <inttypes.h>

extern  char *out;
extern size_t outl;
extern size_t i;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, c = '\x00'; i < outl && i < 1024 && (c = out[i]) != '\n'; i += 2) {
        if (i + 1 < outl && out[i + 1] == '\n') {
            i++;
            break;
        }
    }
}
