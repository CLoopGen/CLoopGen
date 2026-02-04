#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern unsigned long long mu;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned long long temp_mu = 0;
    for (int j = 0; j < size; j++) {
        int idx = size - 1 - j;
        temp_mu += buf[idx] * ((unsigned long long)1 << (8 * j));
    }
    mu = temp_mu;
}
