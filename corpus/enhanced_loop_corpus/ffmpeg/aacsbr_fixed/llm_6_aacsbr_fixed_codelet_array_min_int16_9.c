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
    int16_t temp_min = min;
    for (i = 1; i < nel; i++) {
        temp_min = (array[i] < temp_min) ? array[i] : temp_min;
    }
    min = temp_min;
}
