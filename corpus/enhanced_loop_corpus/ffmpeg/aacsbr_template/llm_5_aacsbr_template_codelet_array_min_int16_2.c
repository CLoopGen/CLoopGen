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
if (nel > 1) {
    for (i = 1; i < nel; i += 2) {
        int16_t candidate = array[i];
        if (i + 1 < nel) {
            if (array[i + 1] < candidate)
                candidate = array[i + 1];
        }
        if (candidate < min)
            min = candidate;
    }
}
}
