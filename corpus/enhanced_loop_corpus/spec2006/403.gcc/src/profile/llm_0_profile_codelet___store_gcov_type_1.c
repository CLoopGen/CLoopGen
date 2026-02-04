#include <stdio.h>

#include <inttypes.h>

extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (; i < bytes; i++) {
        for (j = 0; j < 1; j++) {
            dest[i] = 0;
        }
    }
}
