#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short cache[6];
    int j;
    for (i = 0; i < 6; i++)
        cache[i] = a[i];
    for (j = 0; j < 6; j++)
        b[j] = cache[5 - j]; // Reverse order to eliminate direct loop-carried dependency
}
