#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern float values[400];
extern int m;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    float temp[400];
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            temp[i * board_size + j] = values[((19 + 2) + i * (19 + 1) + j)];
        }
    }
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            values[((19 + 2) + i * (19 + 1) + j)] = temp[i * board_size + j] + 0.;
        }
    }
}
