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
        if ((size_t)i != (bytes - 1)) {
            value = value * 256 + (source[i] & 255);
        } else {
            value = value * 256 + (source[i] & 127);
        }
    }
}
