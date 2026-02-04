#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int i;
extern int sad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sad = 0;
    for (i = 0; i < 64; i++)
        temp_sad += byte_abs[diff[i]];
    sad = temp_sad;
}
