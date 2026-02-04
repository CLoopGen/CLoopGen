#include <stdio.h>

#include <inttypes.h>

extern int j;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        int shift = (size - i - 1) * 8;
        if (shift < 0) continue;
        int divisor = (1 << shift);
        buf[i] = j / divisor;
        j %= divisor;
    }
}
