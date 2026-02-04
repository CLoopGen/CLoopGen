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
        initvalu_temp[i] = initvalu[i] + h2_7 * (finavalu_temp[0][i]);
        if (i + 1 < 91) {
            initvalu_temp[i + 1] = initvalu[i + 1] + h2_7 * (finavalu_temp[0][i + 1]);
        }
        if (i + 2 < 91) {
            initvalu_temp[i + 2] = initvalu[i + 2] + h2_7 * (finavalu_temp[0][i + 2]);
        }
    }
}
