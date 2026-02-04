#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern float temp[54];
extern float gain;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (gain == 1.0f || length <= 0) {
        return;
    }
    for (i = 0; i < length; i++) {
        temp[i] *= gain;
    }
}
