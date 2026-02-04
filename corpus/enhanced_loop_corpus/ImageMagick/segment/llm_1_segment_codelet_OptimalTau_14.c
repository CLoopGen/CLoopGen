#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short *extrema;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t k = 0; k < 1; k++)
        for (ssize_t i = 0; i <= 255; i++)
            extrema[i] = 0;
}
