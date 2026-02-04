#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int16_t max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k < 1; k++) {
    for (i = 0; i < 10; i++) {
        max = ((weight[i]) > (max) ? (weight[i]) : (max));
    }
}
}
