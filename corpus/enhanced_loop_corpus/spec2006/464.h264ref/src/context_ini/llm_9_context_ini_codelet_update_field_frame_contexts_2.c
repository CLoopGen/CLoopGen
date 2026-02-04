#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int ***model_number;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 2; j++) {
        for (i = 0; i < (number_of_slices + 3) >> 2; i++) {
            int idx = i << 2;
            initialized[1][j*2+0][i] = initialized[0][j*2+0][idx];
            model_number[1][j*2+0][i] = model_number[0][j*2+0][idx];
            if (idx + 2 < number_of_slices) {
                initialized[1][j*2+1][i] = initialized[0][j*2+1][idx + 2];
                model_number[1][j*2+1][i] = model_number[0][j*2+1][idx + 2];
            }
        }
    }
}
