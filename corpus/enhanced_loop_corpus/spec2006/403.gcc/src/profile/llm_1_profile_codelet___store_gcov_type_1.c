#include <stdio.h>

#include <inttypes.h>

extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer_i = 0;
    size_t chunk = 1;
    for (; outer_i < (bytes + chunk - 1) / chunk; outer_i++) {
        size_t start = outer_i * chunk;
        size_t end = (start + chunk < bytes) ? start + chunk : bytes;
        for (i = start; i < end; i++) {
            dest[i] = 0;
        }
    }
    i = bytes;
}
