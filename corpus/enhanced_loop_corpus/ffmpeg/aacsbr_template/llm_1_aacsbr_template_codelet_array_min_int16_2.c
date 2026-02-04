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
    for (i = 1; i < nel; i++) {
        if (i % 2 == 1 && (i + 1) < nel) {
            int16_t val1 = array[i];
            int16_t val2 = array[i + 1];
            int16_t local_min = (val1 > val2) ? val2 : val1;
            min = (min > local_min) ? local_min : min;
            i++;
        } else {
            min = ((array[i]) > (min) ? (min) : (array[i]));
        }
    }
}
