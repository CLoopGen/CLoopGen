#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i += 2) {
    weight[i] <<= shift;
    weight[i+1] <<= shift;
    weight[i] += 1;
    weight[i+1] += 1;
}
}
