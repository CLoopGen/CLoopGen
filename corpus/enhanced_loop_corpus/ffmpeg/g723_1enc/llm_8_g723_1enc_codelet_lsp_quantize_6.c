#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int16_t max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 5; i++) {
        max = ((weight[2*i]) > (max) ? (weight[2*i]) : (max));
        max = ((weight[2*i + 1]) > (max) ? (weight[2*i + 1]) : (max));
    }
}
