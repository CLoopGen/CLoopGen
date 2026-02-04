#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_cells;
extern int cell_num;
extern size_t total_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_total = 0; // Eliminate loop-carried WAW on total_size by using a local accumulator
    for (cell_num = 0; cell_num < num_cells; cell_num++) {
        size_t size = (cell_num + 1) * 16;    // Introduce RAW: size computed from cell_num
        local_total += size;                  // Local accumulation removes direct dependency on global total_size
    }
    total_size += local_total; // Single update to global after loop (breaks loop-carried dependency)
}
