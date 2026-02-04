#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int ***model_number;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 4; j++) {
        for (i = 0; i < ((number_of_slices + 1) >> 1); i++) {
            if (model_number[0][j][i << 1] < 0)
                continue;
            initialized[1][j][i] = initialized[0][j][i << 1];
            model_number[1][j][i] = model_number[0][j][i << 1];
        }
    }
}
