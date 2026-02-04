#include <stdio.h>

#include <inttypes.h>

extern unsigned char ivec[16];
extern int n;
extern int rem;
extern int num;
extern unsigned char ovec[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    unsigned char prev = ovec[num] << rem;
    for (i = 0; i < 16; ++i) {
        unsigned char curr_val = ovec[i + num] << rem | ovec[i + num + 1] >> (8 - rem);
        ivec[i] = (i == 0) ? curr_val : curr_val ^ ivec[i-1];
    }
}
