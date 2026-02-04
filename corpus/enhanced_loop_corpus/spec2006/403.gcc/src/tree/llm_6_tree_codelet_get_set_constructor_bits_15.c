#include <stdio.h>

#include <inttypes.h>

extern char *buffer;
extern int bit_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev = 0;
    for (i = 0; i < bit_size; i++) {
        buffer[i] = prev;
        prev = buffer[i] ^ 1;
    }
}
