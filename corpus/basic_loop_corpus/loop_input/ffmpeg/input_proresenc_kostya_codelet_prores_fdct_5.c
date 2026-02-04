#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t linesize;
int16_t *block;
int x;
int y;
uint16_t *tsrc;

static uint16_t tsrc_data[8 * 32768];
static int16_t block_data[8 * 32768];

void init_vars() {
    linesize = 16; 
    block = block_data;
    tsrc = tsrc_data;
    for (int i = 0; i < 8 * 32768; i++) {
        tsrc_data[i] = (uint16_t)(i & 0xFFFF);
    }
    for (int i = 0; i < 8 * 32768; i++) {
        block_data[i] = 0;
    }
}