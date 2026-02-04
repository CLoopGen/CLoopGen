#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 4; ++i) {
        j = i << 1;
        ovec[j] = (ovec[j + num] << rem) | (ovec[j + num + 1] >> (8 - rem));
        ovec[j + 1] = (ovec[j + num + 2] << rem) | (ovec[j + num + 3] >> (8 - rem));
    }
}
