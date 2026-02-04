#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *hist;
extern int32_t *vector;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp[72];
    for (i = 0; i < 72; i++) {
        temp[i] = hist[i];
    }
    for (i = 0; i < 72; i++) {
        vector[72 - i] = temp[i];
    }
}
