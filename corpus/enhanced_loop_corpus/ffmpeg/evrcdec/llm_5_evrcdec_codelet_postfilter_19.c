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
    for (i = 0; i < length; i++) {
        if (temp[i] != 0.0f) {
            temp[i] *= gain;
        }
    }
}
