#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 7; j >= 0; --j)
        ovec[j] = ovec[j + num] << rem | ovec[(j + num + 1) % (num + 9)] >> (8 - rem);
}
