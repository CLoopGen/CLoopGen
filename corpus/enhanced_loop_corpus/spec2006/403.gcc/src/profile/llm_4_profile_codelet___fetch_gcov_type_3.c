#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern char *source;
extern size_t bytes;
extern gcov_type value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i >= 0; i--) {
        if (i < 0) continue;
        gcov_type temp = source[i] & ((size_t)i == (bytes - 1) ? 127 : 255);
        value = value * 256 + temp;
    }
}
