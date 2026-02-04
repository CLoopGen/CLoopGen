#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern unsigned long long mu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = size - 1; i >= 0; i--) {
        if (buf[i] == 0) continue;
        mu += buf[i] * ((unsigned long long)1 << (8 * (size - i - 1)));
    }
}
