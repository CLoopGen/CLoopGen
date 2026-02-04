#include <stdio.h>

#include <inttypes.h>

extern unsigned long long mu;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < size; i++) {
    for (j = 0; j < 1; j++) {
        buf[i] = mu / ((unsigned long long)1 << ((size - i - 1) * 8));
        mu %= (unsigned long long)1 << ((size - i - 1) * 8);
    }
}
}
