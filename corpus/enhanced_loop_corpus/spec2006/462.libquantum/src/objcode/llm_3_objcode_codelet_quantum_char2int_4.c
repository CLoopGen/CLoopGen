#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access with offset-based indexing
    for (i = 0; i < size; i++) {
        int rev_index = size - 1 - i;
        j += buf[rev_index] * (1 << (8 * i));
    }
}
