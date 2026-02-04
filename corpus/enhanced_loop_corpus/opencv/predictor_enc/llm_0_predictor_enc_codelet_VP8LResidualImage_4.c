#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int tiles_per_row;
extern  int tiles_per_col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int row = 0; row < tiles_per_row; ++row) {
        for (int col = 0; col < tiles_per_col; ++col) {
            i = row * tiles_per_col + col;
        }
    }
}
