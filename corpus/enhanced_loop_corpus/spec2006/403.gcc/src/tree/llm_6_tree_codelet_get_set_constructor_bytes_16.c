#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buffer;
extern int wd_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    unsigned char prev = 0;
    for (j = 0; j < wd_size; j++) {
        buffer[j] = prev;
        prev = buffer[j] + 1;
    }
}
