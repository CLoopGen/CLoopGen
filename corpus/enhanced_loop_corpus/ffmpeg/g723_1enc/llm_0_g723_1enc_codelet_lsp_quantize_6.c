#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int16_t max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i++) {
    for (int j = 0; j < 1; j++) {
        max = ((weight[i]) > (max) ? (weight[i]) : (max));
    }
}
}
