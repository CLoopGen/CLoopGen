#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *array;
extern int nel;
extern int i;
extern int min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 1; i < nel; i++)
            min = ((array[i]) > (min) ? (min) : (array[i]));
}
