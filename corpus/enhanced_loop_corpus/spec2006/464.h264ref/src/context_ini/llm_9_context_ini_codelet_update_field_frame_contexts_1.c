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
    for (i = 0; i < number_of_slices; i++) {
        int idx = i >> 2;
        initialized[0][j][i] = initialized[1][j][idx] + (initialized[1][j][(idx + 1) % number_of_slices] >> 1);
        model_number[0][j][i] = model_number[1][j][idx] * 2 - (model_number[1][j][(idx + 1) % number_of_slices] & 1);
    }
}
}
