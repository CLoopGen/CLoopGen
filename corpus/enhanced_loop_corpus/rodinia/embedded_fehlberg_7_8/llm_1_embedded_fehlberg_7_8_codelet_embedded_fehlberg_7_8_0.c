#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 91; i += 3) {
    for (int offset = 0; offset < 3 && (i + offset) < 91; offset++) {
        initvalu_temp[i + offset] = initvalu[i + offset];
    }
}
}
