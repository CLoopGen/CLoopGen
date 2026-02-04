#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int i;
extern int sad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 8; j++)
        for (i = j * 8; i < (j + 1) * 8; i++)
            sad += byte_abs[diff[i]];
}
