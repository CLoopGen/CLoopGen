#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Cell {
    int16_t xpos;
    int16_t ypos;
    int16_t width;
    int16_t height;
    uint8_t tree;
    const int8_t *mv_ptr;
} Cell;

uint8_t requant_tab[8][128];
Cell *cell;
int x;
int vq_index;
uint8_t *ref_block;

void init_vars() {
    // Allocate and initialize ref_block with size large enough to make loop take ~0.01s
    // Assume modern CPU can do ~1e9 array operations/sec -> aim for ~10M iterations
    size_t data_size = 16 << 20; // 16 MB of data
    ref_block = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!ref_block) exit(1);

    // Allocate and initialize cell structure
    cell = (Cell*)malloc(sizeof(Cell));
    if (!cell) exit(1);

    // Set width so that (width << 2) is within allocated ref_block size
    // We want: cell->width << 2 <= data_size
    cell->width = (int16_t)(data_size >> 2); // ensures (width << 2) == data_size

    cell->xpos = 0;
    cell->ypos = 0;
    cell->height = 1;
    cell->tree = 0;
    cell->mv_ptr = NULL;

    // Initialize requant_tab
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 128; j++) {
            requant_tab[i][j] = (uint8_t)((i * 128 + j) % 256);
        }
    }

    // Initialize vq_index to ensure index into requant_tab is valid
    vq_index = 3; // any value where (vq_index & 7) is in [0,7)
}