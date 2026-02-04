#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *data[4];
extern int size[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 3 && data[j + 1]; j++) {
        size[j] = data[j + 1] - data[j];
        if (j > 0)
            size[j] += size[j - 1]; // Introduce WAW and loop-carried dependency: each size depends on previous size
    }
}
