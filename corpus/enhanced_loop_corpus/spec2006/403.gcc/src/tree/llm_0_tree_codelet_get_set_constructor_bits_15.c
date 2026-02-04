#include <stdio.h>

#include <inttypes.h>

extern char *buffer;
extern int bit_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < bit_size; i++) {
        for (j = 0; j < 1; j++) {
            buffer[i] = 0;
        }
    }
}
