#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b12_1;
extern  float b12_6;
extern  float b12_7;
extern  float b12_8;
extern  float b12_9;
extern  float b12_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 3rd element in multiple passes
    // This changes the access pattern to non-consecutive, simulating strided access
    // Three separate loops handle stride-3 access to break spatial locality
    int i;

    // Process elements with offset 0 (0, 3, 6, ...)
    for (i = 0; i < 91; i += 3) {
        initvalu_temp[i] = initvalu[i] + h * (
            b12_1 * finavalu_temp[0][i] +
            b12_6 * finavalu_temp[5][i] +
            b12_7 * finavalu_temp[6][i] +
            b12_8 * finavalu_temp[7][i] +
            b12_9 * finavalu_temp[8][i] +
            b12_10 * finavalu_temp[9][i]
        );
    }

    // Process elements with offset 1 (1, 4, 7, ...)
    for (i = 1; i < 91; i += 3) {
        initvalu_temp[i] = initvalu[i] + h * (
            b12_1 * finavalu_temp[0][i] +
            b12_6 * finavalu_temp[5][i] +
            b12_7 * finavalu_temp[6][i] +
            b12_8 * finavalu_temp[7][i] +
            b12_9 * finavalu_temp[8][i] +
            b12_10 * finavalu_temp[9][i]
        );
    }

    // Process elements with offset 2 (2, 5, 8, ...)
    for (i = 2; i < 91; i += 3) {
        initvalu_temp[i] = initvalu[i] + h * (
            b12_1 * finavalu_temp[0][i] +
            b12_6 * finavalu_temp[5][i] +
            b12_7 * finavalu_temp[6][i] +
            b12_8 * finavalu_temp[7][i] +
            b12_9 * finavalu_temp[8][i] +
            b12_10 * finavalu_temp[9][i]
        );
    }
}
