#include <stdio.h>

#include <inttypes.h>

extern char *buffer;
extern int bit_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < bit_size; i++) {
        if (buffer[i] == 1) {
            continue;
        }
        buffer[i] = 0;
    }
}
