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
    for (i = 1; i < nel && array != NULL; i++) {
        int16_t val = array[i];
        if (val >= min) continue;
        min = val;
    }
}
