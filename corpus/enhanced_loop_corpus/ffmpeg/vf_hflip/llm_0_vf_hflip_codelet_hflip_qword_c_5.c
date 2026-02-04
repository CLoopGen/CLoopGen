#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint64_t *src;
extern uint64_t *dst;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++)
        for (j = 0; j < w; j++)
            dst[j] = src[-j];
}
