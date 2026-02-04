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
uint16 *wa;

static uint32 buffer_size;
static uint32 *cp_buffer;
static uint16 *wr_buffer;
static uint16 *wg_buffer;
static uint16 *wb_buffer;
static uint16 *wa_buffer;

void init_vars() {
    buffer_size = (1 << 20); // ~4MB input, adjust for ~0.01s runtime
    w = buffer_size;

    cp_buffer = aligned_alloc(32, buffer_size * sizeof(uint32));
    wr_buffer = aligned_alloc(32, buffer_size * sizeof(uint16));
    wg_buffer = aligned_alloc(32, buffer_size * sizeof(uint16));
    wb_buffer = aligned_alloc(32, buffer_size * sizeof(uint16));
    wa_buffer = aligned_alloc(32, buffer_size * sizeof(uint16));

    cp = cp_buffer;
    wr = wr_buffer;
    wg = wg_buffer;
    wb = wb_buffer;
    wa = wa_buffer;

    for (uint32 i = 0; i < buffer_size; i++) {
        wr_buffer[i] = (uint16)(i * 31);
        wg_buffer[i] = (uint16)(i * 67);
        wb_buffer[i] = (uint16)(i * 127);
        wa_buffer[i] = (uint16)(i * 17);
    }

    x = 0;
}