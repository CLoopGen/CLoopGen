#include <stdio.h>

#include <inttypes.h>

extern unsigned long long mu;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long long local_mu[8] = {mu}; // Assume max size is 8
    int idx;
    for (i = 0; i < size; i++) {
        idx = size - i - 1;
        buf[i] = (unsigned char)(local_mu[0] >> (idx * 8));
        if (i + 1 < size) {
            local_mu[0] %= (1ULL << (idx * 8));
        }
    }
}
