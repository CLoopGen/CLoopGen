#include <stdio.h>

#include <inttypes.h>

extern char *source;
extern size_t bytes;
extern long value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 4 && i >= 0; j++) {
        value = value * 256 + (source[i] & ((size_t)i == (bytes - 1) ? 127 : 255));
        i--;
    }
}
