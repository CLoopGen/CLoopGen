#include <stdio.h>

#include <inttypes.h>

extern unsigned char ivec[16];
extern int n;
extern int rem;
extern int num;
extern unsigned char ovec[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step;
    for (n = 0; n < 16; n += 2) {
        step = n + num;
        ivec[n] = (ovec[step] << rem) | (ovec[step + 1] >> (8 - rem));
        if (n + 1 < 16) {
            step++;
            ivec[n + 1] = (ovec[step] << rem) | (ovec[step + 1] >> (8 - rem));
        }
    }
}
