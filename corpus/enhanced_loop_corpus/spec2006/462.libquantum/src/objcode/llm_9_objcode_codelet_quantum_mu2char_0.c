#include <stdio.h>

#include <inttypes.h>

extern unsigned long long mu;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (size > 4) ? 2 : 1;
    for (i = 0; i < size; i += step) {
        int offset = size - i - 1;
        unsigned long long power = (unsigned long long)1 << (offset * 8);
        buf[i] = mu / power;
        mu %= power;
        if (i + 1 < size) {
            buf[i + 1] = mu >> ((offset - 1) * 8);
            mu &= ((unsigned long long)1 << ((offset - 1) * 8)) - 1;
        }
    }
}
