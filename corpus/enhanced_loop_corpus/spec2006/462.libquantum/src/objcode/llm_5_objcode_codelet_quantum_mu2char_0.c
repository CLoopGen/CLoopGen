#include <stdio.h>

#include <inttypes.h>

extern unsigned long long mu;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size; i++) {
    if (mu == 0) {
        buf[i] = 0;
        continue;
    }
    buf[i] = mu / ((unsigned long long)1 << ((size - i - 1) * 8));
    mu %= (unsigned long long)1 << ((size - i - 1) * 8);
}
}
