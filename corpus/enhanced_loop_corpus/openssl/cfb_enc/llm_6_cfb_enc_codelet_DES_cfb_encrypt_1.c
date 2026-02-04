#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    unsigned char temp[8];
    for (j = 0; j < 8; ++j)
        temp[j] = ovec[j + num] << rem | ovec[j + num + 1] >> (8 - rem);
    for (j = 0; j < 8; ++j)
        ovec[j] = temp[j];
}
