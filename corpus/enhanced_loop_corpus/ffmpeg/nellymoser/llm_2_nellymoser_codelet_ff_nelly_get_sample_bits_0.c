#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *buf;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 124; i += 4) {
        float temp1 = buf[i];
        float temp2 = (i+1 < 124) ? buf[i+1] : temp1;
        float temp3 = (i+2 < 124) ? buf[i+2] : temp1;
        float temp4 = (i+3 < 124) ? buf[i+3] : temp1;
        max = ((max) > (temp1)) ? max : temp1;
        max = ((max) > (temp2)) ? max : temp2;
        max = ((max) > (temp3)) ? max : temp3;
        max = ((max) > (temp4)) ? max : temp4;
    }
}
