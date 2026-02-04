#include <stdio.h>

#include <inttypes.h>

extern unsigned long long mu;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (size > 0) {
    for (i = 0; i < size; i++) {
        int inner_limit = 1;
        for (int k = 0; k < inner_limit; k++) {
            buf[i] = mu / ((unsigned long long)1 << ((size - i - 1) * 8));
            mu %= (unsigned long long)1 << ((size - i - 1) * 8);
        }
    }
}
}
