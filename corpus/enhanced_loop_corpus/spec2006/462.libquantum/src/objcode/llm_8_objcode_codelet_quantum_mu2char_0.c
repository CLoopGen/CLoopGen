#include <stdio.h>

#include <inttypes.h>

extern unsigned long long mu;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < size && mu > 0; i++) {
        unsigned long long shift_val = (unsigned long long)1 << ((size - i - 1) * 8);
        buf[i] = (unsigned char)(mu / shift_val);
        mu %= shift_val;
        for (j = 0; j < (buf[i] % 3); j++) {
            buf[i] ^= (buf[i] >> j) + (mu & 0xFF);
        }
    }
}
