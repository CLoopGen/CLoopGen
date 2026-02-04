#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_cells;
extern int cell_num;
extern size_t total_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cell_num = 0; cell_num < num_cells; cell_num++) {
        size_t size = cell_num * sizeof(int); // Introduce local dependency: size depends on loop index
        total_size += size;                   // Maintain WAW dependency on total_size (loop-carried)
    }
}
