#include <stdio.h>

#include <inttypes.h>

extern unsigned char ivec[16];
extern int n;
extern int rem;
extern int num;
extern unsigned char ovec[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16; ++n) {
        int index = n * 2; // Strided access with step 2
        ivec[n] = ovec[index + num] << rem | ovec[index + num + 1] >> (8 - rem);
    }
}
