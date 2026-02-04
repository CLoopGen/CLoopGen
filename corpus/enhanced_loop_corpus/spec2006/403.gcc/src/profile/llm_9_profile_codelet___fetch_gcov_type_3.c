#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern char *source;
extern size_t bytes;
extern gcov_type value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (; i >= 0; i -= step) {
        gcov_type high = source[i] & ((size_t)i == (bytes - 1) ? 127 : 255);
        gcov_type low = (i - 1 >= 0) ? (source[i - 1] & 255) : 0;
        value = value * 65536 + (high * 256 + low); // Process two bytes per iteration, reducing trip count
    }
}
