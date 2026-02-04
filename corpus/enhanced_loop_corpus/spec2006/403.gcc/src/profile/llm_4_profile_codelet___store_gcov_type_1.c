#include <stdio.h>

#include <inttypes.h>

extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < bytes; i++) {
        if (dest[i] != 0) {
            dest[i] = 0;
        }
    }
}
