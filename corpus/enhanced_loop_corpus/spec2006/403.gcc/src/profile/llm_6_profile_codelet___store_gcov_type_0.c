#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern gcov_type value;
extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    gcov_type temp_value = value;
    for (i = 0; i < (sizeof(value) < bytes ? sizeof(value) : bytes); i++) {
        char mask = (i == (bytes - 1)) ? 127 : 255;
        dest[i] = temp_value & mask;
        temp_value >>= 8; // Eliminate direct use of division, shift instead; introduces WAW independence via local temp
    }
}
