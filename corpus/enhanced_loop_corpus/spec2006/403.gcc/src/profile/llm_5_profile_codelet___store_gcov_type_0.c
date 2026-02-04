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
        if (value == 0 && i > 0) {
            dest[i] = 0;
        } else {
            dest[i] = value & (i == (bytes - 1) ? 127 : 255);
            value = value / 256;
        }
    }
}
