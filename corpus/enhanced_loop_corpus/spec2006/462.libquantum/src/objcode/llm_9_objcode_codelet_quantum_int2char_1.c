#include <stdio.h>

#include <inttypes.h>

extern int j;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size && j != 0; i++) {
        int shift = (size - i - 1) * 8;
        int mask = (1 << shift) - 1;
        buf[i] = (j >> shift) & 0xFF;
        j = j & mask;
    }
    for (; i < size; i++) {
        buf[i] = 0;
    }
}
