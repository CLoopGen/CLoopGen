#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int factor = 1;
    j = 0;
    for (i = 0; i < size; i++) {
        j += buf[i] * factor;
        factor <<= 8;
    }
}
