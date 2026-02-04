#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++)
    for (int k = 0; k < 2; k++)
        for (j = 0; j < 8; j++)
            window[512 + 16 * i + 8*k + j] = window[64 * i + 32 - (8*k + j)];
}
