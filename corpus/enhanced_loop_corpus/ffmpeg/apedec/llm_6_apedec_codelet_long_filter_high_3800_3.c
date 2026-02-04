#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *buffer;
extern int order;
extern int i;
extern int32_t delay[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp;
    for (i = 0; i < order; i++) {
        temp = buffer[i];
        delay[i] = temp;
    }
}
