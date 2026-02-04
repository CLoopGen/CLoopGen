#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev = weight[0];
    weight[0] <<= shift;
    for (i = 1; i < 10; i++) {
        int16_t current = weight[i];
        weight[i] = (prev + weight[i]) << shift;
        prev = current;
    }
}
