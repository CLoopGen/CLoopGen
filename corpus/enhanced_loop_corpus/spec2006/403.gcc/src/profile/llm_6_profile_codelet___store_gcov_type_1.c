#include <stdio.h>

#include <inttypes.h>

extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    char prev = 0;
    for (j = 0; j < bytes; j++) {
        dest[j] = prev;
        prev = dest[j] + 1;
    }
}
