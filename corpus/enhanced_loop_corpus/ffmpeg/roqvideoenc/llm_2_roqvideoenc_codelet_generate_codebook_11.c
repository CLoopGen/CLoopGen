#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct roq_cell {
    unsigned char y[4];
    unsigned char u;
    unsigned char v;
} roq_cell;

extern roq_cell *results;
extern int cbsize;
extern int i;
extern int j;
extern int k;
extern int c_size;
extern int *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with flattened indexing
    // Instead of using pointer arithmetic on 'results' and dereferencing 'buf' repeatedly,
    // we calculate total iterations and access buffer consecutively.
    int total_cells = cbsize * c_size;
    int *local_buf = buf;
    
    for (i = 0; i < total_cells; i++) {
        roq_cell *cell = &results[i];
        for (j = 0; j < 4; j++) {
            cell->y[j] = local_buf[j];
        }
        cell->u = (local_buf[4] + 1 / 2) / 1;
        cell->v = (local_buf[5] + 1 / 2) / 1;
        local_buf += 6;
    }
}
