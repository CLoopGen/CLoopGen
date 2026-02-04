#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 5; i++)
        for (; j < 9; j++)
            x[k] *= 10;
}
