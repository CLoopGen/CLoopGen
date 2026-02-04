#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern float values[400];
extern int m;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Traverse the array in a strided manner by iterating over n first and then m,
    // which changes the access pattern to jump by strides instead of row-wise
    for (n = 0; n < board_size; n++) {
        for (m = 0; m < board_size; m++) {
            values[(20 + m * 20 + n)] = 0.;
        }
    }
}
