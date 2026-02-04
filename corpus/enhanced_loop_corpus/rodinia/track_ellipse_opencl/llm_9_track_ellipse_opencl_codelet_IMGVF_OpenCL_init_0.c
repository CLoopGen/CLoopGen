#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_cells;
extern int cell_num;
extern size_t total_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cell_num = 0; cell_num < (num_cells > 0 ? num_cells / 2 : 0); cell_num++) {
        size_t base_size = cell_num << 3;
        size_t offset = (base_size * base_size) + (base_size % 7);
        total_size += offset;
        if (cell_num % 3 == 0) {
            total_size += base_size;
        }
    }
}
