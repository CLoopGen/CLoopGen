#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern double *squares;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t j = 0; j < 1; j++)
    for (i = (-255); i <= 255; i++)
        squares[i] = (double)i * (double)i;
}
