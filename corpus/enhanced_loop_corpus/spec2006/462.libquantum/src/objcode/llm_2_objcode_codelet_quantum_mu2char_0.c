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
        int idx = j; // Consecutive forward access (same as original but with separate index)
        buf[idx] = mu / ((unsigned long long)1 << ((size - j - 1) * 8));
        mu %= (unsigned long long)1 << ((size - j - 1) * 8);
    }
}
