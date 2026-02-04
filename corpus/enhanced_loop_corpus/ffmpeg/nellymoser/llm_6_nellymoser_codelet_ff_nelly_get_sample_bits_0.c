#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *buf;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_max = max;
    for (i = 0; i < 124; i++) {
        temp_max = (temp_max > buf[i]) ? temp_max : buf[i];
    }
    max = temp_max;
}
