#include <stdio.h>

#include <inttypes.h>

extern unsigned char ivec[16];
extern int n;
extern int rem;
extern int num;
extern unsigned char ovec[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 4; ++n)
        for (int inner = 0; inner < 4; ++inner)
            ivec[n * 4 + inner] = ovec[(n * 4 + inner) + num] << rem | ovec[(n * 4 + inner) + num + 1] >> (8 - rem);
}
