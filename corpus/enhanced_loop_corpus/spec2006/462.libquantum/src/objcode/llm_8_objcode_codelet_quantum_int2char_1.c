#include <stdio.h>

#include <inttypes.h>

extern int j;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < size; i += step) {
        int shift1 = (size - i - 1) * 8;
        int shift2 = (size - i - 2) * 8;
        if (i < size) {
            buf[i] = j >> shift1;
            j %= (1 << shift1);
        }
        if (i + 1 < size) {
            buf[i + 1] = j >> shift2;
            j %= (1 << shift2);
        }
    }
}
