#include <stdio.h>

#include <inttypes.h>

extern unsigned long long mu;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < size; j++) {
        int idx = size - 1 - j; // Reverse memory access pattern: strided from end to start
        buf[idx] = mu / ((unsigned long long)1 << (j * 8));
        mu %= (unsigned long long)1 << (j * 8);
    }
}
