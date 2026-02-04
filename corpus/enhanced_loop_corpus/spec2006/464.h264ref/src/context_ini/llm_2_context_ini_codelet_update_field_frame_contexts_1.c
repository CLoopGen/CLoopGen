#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int ***model_number;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by swapping loop order for better spatial locality
    for (i = 0; i < number_of_slices; i++) {
        for (j = 0; j < 4; j++) {
            initialized[0][j][i] = initialized[1][j][i >> 1];
            model_number[0][j][i] = model_number[1][j][i >> 1];
        }
    }
}
