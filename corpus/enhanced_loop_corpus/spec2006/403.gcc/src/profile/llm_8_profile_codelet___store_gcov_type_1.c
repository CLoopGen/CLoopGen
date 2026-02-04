#include <stdio.h>

#include <inttypes.h>

extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = i; j < bytes; j += 2) {
        dest[j] = 0;
        if (j + 1 < bytes)
            dest[j + 1] = 0;
    }
    i = bytes; // Ensure completion
}
