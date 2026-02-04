#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern unsigned long long mu;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    mu = 0;
    unsigned long long shift_base = 1;
    for (int j = size - 1; j >= 0; j--) {
        mu += buf[j] * shift_base;
        shift_base <<= 8;
    }
}
