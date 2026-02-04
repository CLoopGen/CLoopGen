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
        ivec[n] = (rem == 0) ? ovec[n + num] : 
                             (ovec[n + num] << rem | ovec[n + num + 1] >> (8 - rem));
    }
}
