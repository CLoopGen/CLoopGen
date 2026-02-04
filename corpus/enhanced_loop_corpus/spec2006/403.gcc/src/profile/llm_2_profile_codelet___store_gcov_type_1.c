#include <stdio.h>

#include <inttypes.h>

extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (; i < bytes; i += step) {
        if (i < bytes) dest[i] = 0;
        if (i + 1 < bytes) dest[i + 1] = 0;
    }
}
