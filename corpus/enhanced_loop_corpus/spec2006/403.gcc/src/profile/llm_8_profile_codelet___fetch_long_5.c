#include <stdio.h>

#include <inttypes.h>

extern char *source;
extern size_t bytes;
extern long value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i >= 0; i -= 2) {
        size_t mask1 = (size_t)i == (bytes - 1) ? 127 : 255;
        value = value * 65536 + ((source[i] & mask1) << 8);
        if (i > 0) {
            size_t mask2 = (size_t)(i-1) == (bytes - 1) ? 127 : 255;
            value += (source[i-1] & mask2);
        }
    }
}
