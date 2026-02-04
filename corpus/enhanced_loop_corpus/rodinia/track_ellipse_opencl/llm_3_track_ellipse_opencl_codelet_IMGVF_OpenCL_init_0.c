#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_cells;
extern int cell_num;
extern size_t total_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < num_cells; i++) {
        size_t size;
        int idx = (i * 3) % num_cells; // Indirect access via computed index
        cell_num = idx;
        total_size += size;
    }
}
