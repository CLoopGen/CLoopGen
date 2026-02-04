#include <stdio.h>

#include <inttypes.h>

extern unsigned long long mu;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    unsigned long long temp_mu = mu;
    for (i = 0; i < size; i++) {
        j = size - i - 1;
        buf[i] = (unsigned char)(temp_mu >> (j * 8));
        temp_mu &= ((1ULL << (j * 8)) - 1);
    }
}
