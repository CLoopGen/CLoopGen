#include <stdio.h>

#include <inttypes.h>

extern char *buffer;
extern int bit_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < bit_size; i += 2) {
        if (i + 1 < bit_size) {
            buffer[i] = 0;
            buffer[i + 1] = 0;
        } else {
            buffer[i] = 0;
        }
    }
}
