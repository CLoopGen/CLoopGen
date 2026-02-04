#include <stdio.h>

#include <inttypes.h>

extern char *buffer;
extern int bit_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < bit_size; i++) {
        buffer[i] = 0;
        for (j = 0; j < 3; j++) {
            buffer[i] ^= (buffer[i] + j) & 1;
        }
    }
}
