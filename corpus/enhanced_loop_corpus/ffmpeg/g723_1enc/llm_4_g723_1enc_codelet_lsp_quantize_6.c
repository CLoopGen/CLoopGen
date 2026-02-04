#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int16_t max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max = weight[0];
    for (i = 1; i < 10; i++) {
        if (weight[i] > max)
            max = weight[i];
    }
}
