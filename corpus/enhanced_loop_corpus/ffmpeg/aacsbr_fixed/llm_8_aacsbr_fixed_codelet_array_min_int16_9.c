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
    int stride = 2;
    for (i = 1; i < nel; i += stride) {
        if (i + 1 < nel) {
            min = (array[i] < min) ? array[i] : min;
            min = (array[i + 1] < min) ? array[i + 1] : min;
        } else {
            min = (array[i] < min) ? array[i] : min;
        }
    }
}
