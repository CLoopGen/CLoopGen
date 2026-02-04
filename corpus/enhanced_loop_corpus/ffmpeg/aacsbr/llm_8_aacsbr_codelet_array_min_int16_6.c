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
    for (i = 0; i < nel; i += 2) {
        int16_t val1 = array[i];
        int16_t val2 = (i + 1 < nel) ? array[i + 1] : val1;
        int16_t local_min = (val1 < val2) ? val1 : val2;
        min = (local_min < min) ? local_min : min;
    }
}
