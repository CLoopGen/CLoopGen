#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint32;
typedef unsigned short uint16;

uint32 *cp;
uint32 x;
uint32 w;
uint16 *wr;
uint16 *wg;
uint16 *wb;

static uint32 *cp_buffer;
static uint16 *wr_buffer;
static uint16 *wg_buffer;
static uint16 *wb_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements to target ~0.01s runtime
    w = data_size;

    cp_buffer = (uint32*)aligned_alloc(32, w * sizeof(uint32));
    wr_buffer = (uint16*)aligned_alloc(32, w * sizeof(uint16));
    wg_buffer = (uint16*)aligned_alloc(32, w * sizeof(uint16));
    wb_buffer = (uint16*)aligned_alloc(32, w * sizeof(uint16));

    if (!cp_buffer || !wr_buffer || !wg_buffer || !wb_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(cp_buffer, 0, w * sizeof(uint32));
    for (size_t i = 0; i < w; i++) {
        wr_buffer[i] = (uint16)((i * 0x9E37) & 0xFFFF);
        wg_buffer[i] = (uint16)(((i + 100) * 0x9E37) & 0xFFFF);
        wb_buffer[i] = (uint16)(((i + 200) * 0x9E37) & 0xFFFF);
    }

    cp = cp_buffer;
    wr = wr_buffer;
    wg = wg_buffer;
    wb = wb_buffer;
}