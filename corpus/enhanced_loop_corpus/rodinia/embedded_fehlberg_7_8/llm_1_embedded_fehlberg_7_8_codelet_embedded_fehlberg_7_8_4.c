#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b51;
extern  float b53;
extern  float b54;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i += 3) {
        for (int offset = 0; offset < 3 && (i + offset) < 91; offset++) {
            int idx = i + offset;
            initvalu_temp[idx] = initvalu[idx] + h * (b51 * finavalu_temp[0][idx] + b53 * finavalu_temp[2][idx] + b54 * finavalu_temp[3][idx]);
        }
    }
}
