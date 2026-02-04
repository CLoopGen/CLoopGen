#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *last;
extern int *Y;
extern int Ystride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp;
for (i = 0; i < 8; i += 2) {
    temp = i + Ystride * 3;
    last[i] = Y[temp];
    if (i + 1 < 8) last[i + 1] = Y[temp + 1];
}
}
