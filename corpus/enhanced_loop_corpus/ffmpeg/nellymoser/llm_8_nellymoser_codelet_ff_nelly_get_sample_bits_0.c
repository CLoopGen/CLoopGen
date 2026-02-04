#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *buf;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    max = buf[0];
    for (i = 1; i < 124; i += 2) {
        if (i + 1 < 124) {
            float val1 = buf[i];
            float val2 = buf[i + 1];
            int temp_max = (val1 > val2) ? val1 : val2;
            max = (max > temp_max) ? max : temp_max;
        } else {
            max = (max > buf[i]) ? max : buf[i];
        }
    }
}
