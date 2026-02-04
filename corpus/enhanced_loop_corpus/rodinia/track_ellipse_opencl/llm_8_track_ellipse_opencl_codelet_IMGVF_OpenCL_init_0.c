#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_cells;
extern int cell_num;
extern size_t total_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cell_num = 0; cell_num < num_cells * 2; cell_num += 2) {
        size_t size = cell_num * 4 + 1;
        total_size += size;
        total_size += size / 2;
        total_size -= size / 4;
    }
}
