#include <stdio.h>

#include <inttypes.h>

extern char *source;
extern size_t bytes;
extern long value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long local_value = 0;
    int local_i = i;
    while (local_i >= 0) {
        local_value += (source[local_i] & ((size_t)local_i == (bytes - 1) ? 127 : 255)) << (8 * (i - local_i));
        local_i--;
    }
    value = local_value;
}
