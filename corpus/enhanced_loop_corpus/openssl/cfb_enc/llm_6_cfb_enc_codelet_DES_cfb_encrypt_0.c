#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[8];
    for (i = 0; i < 8; ++i)
        temp[i] = ovec[i + num] << rem | ovec[i + num + 1] >> (8 - rem);
    for (i = 0; i < 8; ++i)
        ovec[i] = temp[i];
}
