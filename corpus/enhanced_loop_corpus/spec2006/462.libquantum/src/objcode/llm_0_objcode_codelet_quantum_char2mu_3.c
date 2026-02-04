#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern unsigned long long mu;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int j;
    for (j = 0; j < size; j++) {
        i = size - 1 - j;
        mu += buf[i] * ((unsigned long long)1 << (8 * j));
    }
}
