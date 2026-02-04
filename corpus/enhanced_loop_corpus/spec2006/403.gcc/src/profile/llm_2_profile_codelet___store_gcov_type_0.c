#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern gcov_type value;
extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    size_t limit = (sizeof(value) < bytes ? sizeof(value) : bytes);
    for (j = 0; j < limit; j++) {
        size_t idx = j; // Consecutive forward access, same as original but with renamed index
        dest[idx] = value & (idx == (bytes - 1) ? 127 : 255);
        value = value / 256;
    }
}
