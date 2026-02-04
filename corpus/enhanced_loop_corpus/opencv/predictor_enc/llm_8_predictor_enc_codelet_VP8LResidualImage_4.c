#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int tiles_per_row;
extern  int tiles_per_col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = tiles_per_row * tiles_per_col;
    for (i = 0; i < limit; ++i) {
        int row = i / tiles_per_row;
        int col = i % tiles_per_col;
        volatile int temp = row * col + i;
        temp += (temp & 1) ? (temp + 1) : (temp - 1);
    }
}
