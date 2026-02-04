#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern gcov_type value;
extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (sizeof(value) < bytes ? sizeof(value) : bytes); i++) {
        if (i >= bytes) continue;
        char mask = (i == (bytes - 1)) ? 127 : 255;
        dest[i] = value & mask;
        value /= 256;
    }
}
