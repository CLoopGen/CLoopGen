#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern gcov_type value;
extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = (sizeof(value) < bytes ? sizeof(value) : bytes);
    for (i = 0; i < limit; i++) {
        char temp = value & (i == (bytes - 1) ? 127 : 255);
        value = value / 256;
        dest[i] = temp;
    }
}
