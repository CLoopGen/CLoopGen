#include <stdio.h>

#include <inttypes.h>

extern char *buffer;
extern int bit_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < bit_size; i += stride) {
        buffer[i] = 0;
        if (i + 1 < bit_size) {
            buffer[i + 1] = 0;
        }
    }
}
