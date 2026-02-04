#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float h2_7;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i += 3) {
        for (int offset = 0; offset < 3 && (i + offset) < 91; offset++) {
            int idx = i + offset;
            initvalu_temp[idx] = initvalu[idx] + h2_7 * (finavalu_temp[0][idx]);
        }
    }
}
